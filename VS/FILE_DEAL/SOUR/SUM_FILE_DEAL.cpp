#include "main.h"

const char* Table_name = { "\"start_time\",\"end_time\",\"AHI\",\"CAI\",\"HI\",\"SI\",\"FL\",\"RERA\",\"CSR\",\"AVGLEAK\",\"AvgP\",\"MinSPO2\",\"AvgSPO2\",\"AvgSPO2\",\"MaxPR\",\"MinPR\",\"TCount\",\"TTreat\",\"SN\",\"SetCount\"\n" };




int summer_csv(void)
{
    Data_relog summer_deal;
    char ch_get[50];
    const size_t numBytes = 50;
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
        memcpy(&summer_deal, &ch_get[2], 48);
        memset(&ch_get, 0, 50);
      
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


    }

    FileHandler::SUMMER_DATA.close(); // 关闭文件
    file_summer_csv.close(); // 关闭文件
    return 1;
}