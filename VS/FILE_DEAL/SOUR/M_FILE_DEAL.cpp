#include "main.h"
#include <ctime>
#include <chrono>
#include <atomic>
#include <sstream>
const char* M_FILE_name = { "\"Time\",\"Press\",\"Flow\",\"OAI\",\"CAI\",\"HI\",\"SI\",\"FL\",\"RERA\",\"CSR\",\"LVT\",\"VT\",\"MV\",\"IE\",\"RR\",\"SPOP2\",\"PR\",\"End\"\n" };

// 假设你有一个数据结构来存储数据
struct Data_m_file
{
    unsigned char Press;     //当前压力    1  单水平压力=Value*0.1;
    unsigned char Flow;      //血氧        2
    unsigned char OAI;       //脉率        3	
    unsigned char CAI;        //AI         4     
    unsigned char HI;        //HI          5
    unsigned char SI;        //CSA         6
    unsigned char FL;        //SI          7
    unsigned char RERA;      //RERA        8
    unsigned char CSR;        //PB CSR     9
    unsigned char LVT;       //漏气量      10
    unsigned short VT;       //潮气量      11   12
    unsigned char MV;       //分钟通气量    13
    unsigned char IE;       //吸气占比      14
    unsigned char RR;       //呼吸率      15
    unsigned char SPO2;       //血氧      16
    unsigned char PR;       //脉率      17
    unsigned char End;       //结束符     18
};
struct Time_M_FILE
{
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
};


Time_M_FILE M_FILE_Time;
volatile uint8_t isLeapYearFlag = 0; // 是否为闰年标志
// 闰年判断函数
uint8_t isLeapYear(uint16_t year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // 是闰年
    }
    return 0; // 不是闰年
}



int m_file_csv(void)
{
    char ch_get[18];
    std::string TIMR_GET;
    Data_m_file M_FILE_deal;

    const size_t numBytes = 18; // 确保这个值大于512
    // 打开文件流
    std::ofstream file_M_DATA_csv("OUT/m_flie_data.csv");
    if (!file_M_DATA_csv.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }
    // 写入列标题
    file_M_DATA_csv << M_FILE_name;

    memset(&ch_get, 0, 18);
    FileHandler::M_FILE_DATA.read(ch_get, 8);
    memcpy(&M_FILE_Time, ch_get, sizeof(M_FILE_Time));
    if (FileHandler::M_FILE_DATA.gcount() != 8)
    {
        std::cerr << "Failed to read the required number of bytes." << std::endl;
        return 1; // 如果没有读取到预期的字节数，退出循环
    }
    for (size_t tick_fila = 0; ;tick_fila++)
    {
        // 读取固定字节数到缓冲区
        FileHandler::M_FILE_DATA.read(ch_get, numBytes);
        if (FileHandler::M_FILE_DATA.gcount() != numBytes)
        {
            std::cerr << "Failed to read the required number of bytes." << std::endl;
            break; // 如果没有读取到预期的字节数，退出循环
        }

        memcpy(&M_FILE_deal, &ch_get, 18);
        memset(&ch_get, 0, 18);
        file_M_DATA_csv << (int)M_FILE_Time.year+2000 << "-" << (int)M_FILE_Time.month << "-" << (int)M_FILE_Time.day << " "\
            << (int)M_FILE_Time.hour << ":" << (int)M_FILE_Time.min << ":" << (int)M_FILE_Time.sec<< ","\
            << (int)M_FILE_deal.Press<<"," << (int)M_FILE_deal.Flow << "," << (int)M_FILE_deal.OAI << ","\
            << (int)M_FILE_deal.CAI << "," << (int)M_FILE_deal.HI << "," << (int)M_FILE_deal.SI << ","\
            << (int)M_FILE_deal.FL << "," << (int)M_FILE_deal.RERA << "," << (int)M_FILE_deal.CSR << ","\
            << (int)M_FILE_deal.LVT << "," << (int)M_FILE_deal.VT << "," << (int)M_FILE_deal.MV << "," \
            << (int)M_FILE_deal.IE << "," << (int)M_FILE_deal.RR << "," << (int)M_FILE_deal.SPO2 << "," \
            << (int)M_FILE_deal.PR << "," << (int)M_FILE_deal.End << ","  \
            << "\n";
        M_FILE_Time.min++;
        if (M_FILE_Time.min == 60)
        {
            M_FILE_Time.min = 0;
            M_FILE_Time.hour++;
            if (M_FILE_Time.hour == 24)
            {
                M_FILE_Time.hour = 0;
                M_FILE_Time.day++;
                if(M_FILE_Time.day==30)
                {
                    M_FILE_Time.day = 0;
                }
            }
        }
    }


    FileHandler::M_FILE_DATA.close(); // 关闭文件
    file_M_DATA_csv.close(); // 关闭文件
    return 1;
}