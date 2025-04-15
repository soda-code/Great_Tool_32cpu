#include "./IAP/iap.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/STMFLASH/stmflash.h"
#include "./BSP/LCD/lcd.h"
#include "./FATFS/exfuns/exfuns.h"
#include "./BSP/LED/led.h"
#include "./BSP/BEEP/Beep.h"
#include "./BSP/CRC/CRC.h"
#include "./BSP/LCD/lcd.h"

#include "string.h"
extern FRESULT f_res;
FIL filedst;	
char file_name_SD[50]="0:/";
char file_name_NOR[50]="1:/";


//*****************************************************************************************
 //********************************搜寻文件
 //** @brief       搜寻要烧写的文件
 //** @param        
 //** @param       
 //** @retval      return_type:
 //									1: 0x00 搜寻到要烧录文件
 //									2: 0xff 没有搜寻到烧录文件
//*****************************************************************************************



uint8_t Scanf_File_Name(uint8_t STORE_TYPE)
{
	static FILINFO fno;
	uint8_t return_type=0XFF;
	uint8_t i=0;
	DIR dir;
	
	if(0x00==STORE_TYPE)
	{
		if(0x00 == f_opendir(&dir,"0:/")) //打开目录，返回状态 和 目录对象的指针
		{
			for(;;)
			{
				if(0x00==f_res)
				{
					f_res = f_readdir(&dir, &fno);  // 读取目录项
					if (f_res != FR_OK || fno.fname[0] == 0)
					{
						break;  // 错误或到达目录末尾
					}
					else
					{
						if(memcmp(fno.fname,"YW_BC3_",7)==0)
						{
							return_type=f_typetell(fno.fname);//匹配类型文件
							for(i=0;i<43;i++)
							{
									file_name_SD[3+i]=	fno.fname[i];
							}
						}
						memset(fno.fname,0,sizeof(fno.fname));
					}
				 }
			}
		}
	}
	else
	{
		if(0x00 == f_opendir(&dir,"1:/")) //打开目录，返回状态 和 目录对象的指针
		for(;;)
		{
				f_res = f_readdir(&dir, &fno);  // 读取目录项
				if (f_res != FR_OK || fno.fname[0] == 0)
				{
					break;  // 错误或到达目录末尾
				}
				else
				{
					if(memcmp(fno.fname,"YW_BC3_",7)==0)
					{
						return_type=f_typetell(fno.fname);//匹配类型文件
						for(i=0;i<43;i++)
						{
								file_name_NOR[3+i]=	fno.fname[i];
						}
					}
					memset(fno.fname,0,sizeof(fno.fname));
				}

		}
	}
	return return_type;
}

//*****************************************************************************************
 //********************************烧写文件完成后的工作
 //** @brief       
 //** @param        
 //** @param       
 //** @retval      return_type:
//*****************************************************************************************

OTA_INF_TO_FLASH Flash_OTA_INF={0};		  /* 2K字节缓存 */

extern GUI_CONST_STORAGE GUI_BITMAP bmok;
void WRITE_CPU_End(void)
{
	uint32_t fwaddr;
	uint32_t flash_buf[512]={0};       /* 2K字节缓存 */

	//**********************清除A区FLASH
	memset(flash_buf,0xff,sizeof(flash_buf));
	for(fwaddr=FLASH_APP1_ADDR;fwaddr<=FLASH_APP1_ADDR_END;fwaddr+=2048)
	{
		stmflash_write(fwaddr+FLASH_APP1_ADDR, flash_buf, 512);	/* 将最后的一些内容字节写进去 */
	}

	//***********************************写入正在写入表示
	Flash_OTA_INF.write_staute=1;
	stmflash_write(0x08100000, &Flash_OTA_INF,sizeof(Flash_OTA_INF));
	for(fwaddr=0;fwaddr<=Flash_OTA_INF.END_addr;fwaddr+=2048)
	{
		stmflash_read(fwaddr+FLASH_APP2_ADDR, flash_buf, 512);
		stmflash_write(fwaddr+FLASH_APP1_ADDR, flash_buf, 512);	/* 将最后的一些内容字节写进去 */
	}
	//***********************************写入写入完成表示
	Flash_OTA_INF.write_staute=0;
	stmflash_write(0x08100000, (uint32_t *)&Flash_OTA_INF,sizeof(Flash_OTA_INF));
	lcd_show_string(208,180,64,40,"100%");//crc校验完成后100%
	BUZZER_ON;
	LED0(1);
	delay_ms(2000);
	show_pic(&bmok,210,100);
	LED0(0);
	BUZZER_OFF;
	delay_ms(2000);

}

//*****************************************************************************************
 //********************************烧写文件
 //** @brief       要烧写的文件写入flash
 //** @param        
 //** @param       
 //** @retval      return_type:
 //									1: 0x00 搜寻到要烧录文件
 //									2: 0xff 没有搜寻到烧录文件
//*****************************************************************************************



update_head_info_t bin_head = {0};
uint16_t lenth=0;
uint8_t Write_APP(uint8_t STORE_TYPE)
{
	uint32_t i=0;
	uint32_t fwaddr;
	uint32_t flash_temp=0;
	uint8_t get_char[4]={0};
	uint32_t flash_buf[512]={0};       /* 2K字节缓存 */
	uint32_t CRC_RES=0;
	char dis_play[6]={0};
	static uint32_t adress_get=0;
	
	if(0x00==STORE_TYPE)
	{
		f_res = f_open(&filedst, file_name_SD, FA_READ);
	}
	else
	{
		f_res = f_open(&filedst, file_name_NOR, FA_READ);
	}
		
	if((f_res==0)&&(filedst.obj.objsize>102400))
	{	
		//************************************************成功打开10%
		show_pic(&bmwait,210,100);
		lcd_show_string(200,180,64,40,"10%");//crc校验完成后100%
		//*****************************解析 64byte
	
		f_res = f_read(&filedst,(void *)&bin_head,sizeof(bin_head), &br);
		if(((filedst.obj.objsize)!=(bin_head.bin_size+64))||(bin_head.bin_size>869*1024))//判断文件大小是否异常
		{
			return 0XFF;
		}
	
		fwaddr = FLASH_APP2_ADDR; //写入B区
		//********************************************************************起始字节校验成功
		lcd_show_string(200,180,64,40,"20%");//crc校验完成后100%
		for(;;)
		{
			//memset(get_char,0xFF,sizeof(get_char));

			f_res = f_read(&filedst,get_char,sizeof(get_char), &br);
			if(FR_OK!=f_res)
			{
				return 0XFF;
			}	
			flash_temp  = (uint32_t)get_char[3] << 24;
			flash_temp |= (uint32_t)get_char[2] << 16;
			flash_temp |= (uint32_t)get_char[1] << 8;
			flash_temp |= (uint32_t)get_char[0];
			flash_buf[i] = flash_temp;
			memset(get_char,0x00,4);
			i++;
			//if(filedst.fptr>=filedst.obj.objsize)
			if(filedst.fptr>=filedst.obj.objsize)
			{
				break;
			}
			if(i == 512)
			{
				i = 0;
				stmflash_write(fwaddr, flash_buf, 512);
				fwaddr += 2048;	/* 偏移2048	16 = 2 * 8	所以要乘以2 */
				sprintf(dis_play,"%3ld%%",((filedst.fptr*80/filedst.obj.objsize)+20));//文件大小占用为20%-100% 
				lcd_show_string(200,180,64,40,dis_play);

			}				
		}
		if (i)
		{
			stmflash_write(fwaddr, flash_buf, i);	/* 将最后的一些内容字节写进去 */
		}
		f_close(&filedst);
		//*********************************************CRC计算
		CRC_RES=crc32((const unsigned char *)FLASH_APP2_ADDR, (uint32_t)bin_head.bin_size);
		if(CRC_RES!=bin_head.crc_code)
		{
			return 0XFF;
		}
		//*******************************************************B区已经写入完成
		
		Flash_OTA_INF.crc_code=CRC_RES;							//***记录crc校验
		Flash_OTA_INF.bin_size=bin_head.bin_size;				//***记录长度
		Flash_OTA_INF.END_addr=fwaddr-FLASH_APP2_ADDR;		//***记住地址
		stmflash_write(0x08100000, (uint32_t *)&Flash_OTA_INF,sizeof(Flash_OTA_INF));
		WRITE_CPU_End();
		return 0;
	}

	return 0XFF;
}



//*****************************************************************************************
 //********************************烧写app程序
 //** @brief       将sd卡中的app程序烧录到flash
 //** @param       STORE_TYPE  0->sd  1->Norflash
 //** @param        
 //** @param       
 //** @retval      0, 正常;  其他, 错误代码(详见SD_Error定义);
//*****************************************************************************************

uint8_t Write_Flash_For_SD_NOR(uint8_t STORE_TYPE)
{

	//********************************开显示
	LCD_Fill(0,0,480,320,BLACK);
	HAL_GPIO_WritePin(GPIOB , GPIO_PIN_15,GPIO_PIN_SET);//*关背光


	delay_ms(1000);
	if(0x00==STORE_TYPE)
	{
		f_res = f_mount(fs[0],"0:",1);//挂载sd文件系统	
	}
	else
	{
		f_res = f_mount(fs[1],"1:",1);//挂载norflash文件系统	
	}
	if(0x00!=f_res)//****挂载不成功退出
	{
		return 1;
	}
	f_res=Scanf_File_Name(STORE_TYPE);
	if(0x00!=f_res)//****搜寻文件不成功退出
	{
		return 1;
	}
	LED0(0);
	if(Write_APP(STORE_TYPE)==0xff)
	{
		return 1;
	}
	

	return 0;
}




iapfun jump2app;

/**
 * @brief       跳转到应用程序段(执行APP)
 * @param       appxaddr : 应用程序的起始地址
 * @retval      无
 */

void iap_load_app(uint32_t appxaddr)
{
    uint8_t i=0;
    if (((*(volatile  uint32_t *)appxaddr) & 0x2FF00000) == 0x20000000)     /* 检查栈顶地址是否合法 */
    {
    		HAL_GPIO_WritePin(GPIOB , GPIO_PIN_15,GPIO_PIN_RESET);//*关背光
    		LCD_Clear(BLACK);
        /* 用户代码区第二个字为程序开始地址(复位地址) */
        jump2app = (iapfun) * (volatile uint32_t *)(appxaddr + 4);
        

        /* 关闭全局中断 */
        sys_intx_disable(); 

        /* 关闭滴答定时器，复位到默认值 */
        SysTick->CTRL = 0;
        SysTick->LOAD = 0;
        SysTick->VAL = 0;

        /* 设置所有时钟到默认状态，使用HSI时钟 */
        HAL_RCC_DeInit();

        /* 关闭所有中断，清除所有中断挂起标志 */
        for (i = 0; i < 8; i++)
        {
            NVIC->ICER[i]=0xFFFFFFFF;
            NVIC->ICPR[i]=0xFFFFFFFF;
        }	

        /* 使能全局中断 */
        sys_intx_enable();

        /* 初始化APP堆栈指针(用户代码区的第一个字用于存放栈顶地址) */
        sys_msr_msp(*(volatile uint32_t *)appxaddr);
 
        /* 跳转到APP */
        jump2app();
			
    }
}












