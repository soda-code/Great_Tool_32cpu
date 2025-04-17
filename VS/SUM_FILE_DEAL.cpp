#include "main.h"
#if STORE_SIGNAL
const char* Table_name = { "\"start_time\",\"end_time\",\"AHI\",\"CAI\",\"HI\",\"SI\",\"FL\",\"RERA\",\"CSR\",\"AVGLEAK\",\"AvgP\",\"MinSPO2\",\"AvgSPO2\",\"MaxPR\",\"MinPR\",\"TCount\",\"TTreat\",\"SN\",\"SetCount\"\n" };
#elif STORE_DOUBLE
const char* Table_name = { "\"start_time\",\"end_time\",\"AHI\",\"OAI\",\"CAI\",\"HI\",\"SI\",\"FL\",\"RERA\",\"CSR\",\"AVGLEAK\",\"AvgInsP\",\"AvgExp\",\"MinSPO2\",\"AvgSPO2\",\"MaxPR\",\"MinPR\",\"TCount\",\"TTreat\",\"SN\",\"SetCount\"\n" };
#endif
struct Data_relog 
{
    uint8_t Version;  //协议版本    0
    uint8_t DeviceLevel;//机器型号   1  
    uint8_t start_year;
    uint8_t start_month;
    uint8_t start_day;
    uint8_t start_hour;
    uint8_t start_min;
    uint8_t start_sec;
    uint8_t end_year;
    uint8_t end_month;
    uint8_t end_day;
    uint8_t end_hour;
    uint8_t end_min;
    uint8_t end_sec;
#if STORE_SIGNAL
    unsigned char AHI;      //14
    unsigned char OAI;      //15
    unsigned char CAI;      //16
    unsigned char HI;       //17
    unsigned char SI;       //鼾声指数18
    unsigned char FL;       //气流受限19
    unsigned char RERA;      //觉醒指数呼吸努力度20
    unsigned char CSR;      //周期性呼吸 陈氏呼吸21
    unsigned char AvgLeak; //平均漏气量 22
    unsigned char AvgP; //平均压力  P=Value*0.5   23
#elif STORE_DOUBLE
    unsigned short AHI;      //14
    unsigned short OAI;      //15
    unsigned short CAI;      //16
    unsigned short HI;       //17
    unsigned short SI;       //鼾声指数18
    unsigned short FL;       //气流受限19
    unsigned short RERA;      //觉醒指数呼吸努力度20
    unsigned short CSR;      //周期性呼吸 陈氏呼吸21
    unsigned short AvgLeak; //平均漏气量 22
    unsigned short AvgInsP; //平均压力  P=Value*0.5   23
    unsigned short AvgExp; //平均压力  P=Value*0.5   23
#endif
    unsigned char MinSPO2; //最小血氧 24
    unsigned char AvgSPO2; //平均血氧 25
    unsigned char MaxPR; //最大脉率 26
    unsigned char MinPR; //最小脉率 27
    unsigned short TCount; //使用时间 28 29
    unsigned short TTreat; //治疗时间 30 31
    unsigned char SN[16];  //sn号 32-47
    unsigned short SetCount; //参数修改次数48 49
};
#define  numBytes  sizeof(Data_relog)
int summer_csv(void)
{
    Data_relog summer_deal;
    char ch_get[numBytes];
    // 打开文件流
    std::ofstream file_summer_csv("OUT/summer_data.csv");
    if (!file_summer_csv.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }
    // 写入列标题
    file_summer_csv << Table_name;
    for (size_t tick_fila = 0; ; ++tick_fila)
    {
        // 读取固定字节数到缓冲区
        FileHandler::SUMMER_DATA.read(ch_get, numBytes);
        if (FileHandler::SUMMER_DATA.gcount() != numBytes)
        {
            std::cerr << "Failed to read the required number of bytes." << std::endl;
            break; // 如果没有读取到预期的字节数，退出循环
        }
        memcpy(&summer_deal, &ch_get, numBytes);
        memset(&ch_get, 0, numBytes);
        #if STORE_SIGNAL
            file_summer_csv << (int)summer_deal.start_year << "-" << (int)summer_deal.start_month << "-" << (int)summer_deal.start_day << " "\
            << (int)summer_deal.start_hour << ":" << (int)summer_deal.start_min << ":" << (int)summer_deal.start_sec << ","\
            << (int)summer_deal.end_year << "-" << (int)summer_deal.end_month << "-" << (int)summer_deal.end_day << " "\
            << (int)summer_deal.end_hour << ":" << (int)summer_deal.end_min << ":" << (int)summer_deal.end_sec << "," \
            << (int)summer_deal.AHI << "," << (int)summer_deal.OAI << "," << (int)summer_deal.CAI << "," << (int)summer_deal.HI << ","  \
            << (int)summer_deal.SI << "," << (int)summer_deal.FL << "," << (int)summer_deal.RERA << "," << (int)summer_deal.CSR << ","  \
            << (int)summer_deal.AvgLeak << "," << (int)summer_deal.AvgP << "," << (int)summer_deal.MinSPO2 << "," << (int)summer_deal.AvgSPO2 << ","  \
            << (int)summer_deal.MaxPR << "," << (int)summer_deal.MinPR << "," << (int)summer_deal.TCount << "," << (int)summer_deal.TTreat << ","  \
            << summer_deal.SN << "," << (int)summer_deal.SetCount\
            << "\n";
        #elif STORE_DOUBLE
            file_summer_csv << (int)summer_deal.start_year << "-" << (int)summer_deal.start_month << "-" << (int)summer_deal.start_day << " "\
            << (int)summer_deal.start_hour << ":" << (int)summer_deal.start_min << ":" << (int)summer_deal.start_sec << ","\
            << (int)summer_deal.end_year << "-" << (int)summer_deal.end_month << "-" << (int)summer_deal.end_day << " "\
            << (int)summer_deal.end_hour << ":" << (int)summer_deal.end_min << ":" << (int)summer_deal.end_sec << "," \
            << (int)summer_deal.AHI << "," << (int)summer_deal.OAI << "," << (int)summer_deal.CAI << "," << (int)summer_deal.HI << ","  \
            << (int)summer_deal.SI << "," << (int)summer_deal.FL << "," << (int)summer_deal.RERA << "," << (int)summer_deal.CSR << ","  \
            << (int)summer_deal.AvgLeak << "," << (int)summer_deal.AvgInsP << "," << (int)summer_deal.AvgExp << "," << (int)summer_deal.MinSPO2 << "," << (int)summer_deal.AvgSPO2 << ","  \
            << (int)summer_deal.MaxPR << "," << (int)summer_deal.MinPR << "," << (int)summer_deal.TCount << "," << (int)summer_deal.TTreat << ","  \
            << summer_deal.SN << "," << (int)summer_deal.SetCount\
            << "\n";
        #endif
    }
    FileHandler::SUMMER_DATA.close(); // 关闭文件
    file_summer_csv.close(); // 关闭文件
    return 1;
}