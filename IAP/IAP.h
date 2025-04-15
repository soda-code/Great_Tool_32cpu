#ifndef __IAP_H
#define __IAP_H

#include "./SYSTEM/sys/sys.h"

typedef struct {

	uint32_t info_len;  
	char     hd_version[4];     
	char     fw_version[4];
	uint32_t bin_size;         
	uint32_t start_addr;        
	uint32_t create_time; 
	char     custom_data[36]; 
	uint32_t crc_code;   
}update_head_info_t;


typedef struct 
{
	uint32_t info_len;  
	uint32_t bin_size;         
	uint32_t END_addr;        
	uint32_t create_time; 
	uint32_t crc_code;  
	uint32_t write_staute;//B区向A区写入标识
	uint32_t start_staute;//跳转启动标识
}OTA_INF_TO_FLASH;


typedef void (*iapfun)(void);                   /* 定义一个函数类型的参数 */

// ************************************* 保留 0X08000000~0X0801FFFF(共128KB) 的空间给 Bootloader 使用

#define FLASH_APP1_ADDR         0x08020000      //* 第一个应用程序起始地址(存放在内部FLASH)
#define FLASH_APP1_ADDR_END     0x08100000      //* 第一个应用程序起始地址(存放在内部FLASH)

#define FLASH_APP2_ADDR         0x08120000      //* 第二个应用程序起始地址(存放在内部FLASH)
                                            
uint8_t Write_Flash_For_SD_NOR(uint8_t STORE_TYPE);


void WRITE_CPU_End(void);
void iap_load_app(uint32_t appxaddr);           /* 跳转到APP程序执行 */
void iap_write_appbin(uint32_t appxaddr,uint8_t *appbuf,uint32_t applen);   /* 在指定地址开始,写入bin */

#endif







































