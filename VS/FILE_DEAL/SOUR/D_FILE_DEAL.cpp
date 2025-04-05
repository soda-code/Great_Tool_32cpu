#include "main.h"

const char* D_FILE_name = { "\"Press\",\"Flow\",\"OAI\",\"CAI\",\"HI\",\"SI\",\"FL\",\"RERA\",\"CSR\",\"LVT\",\"VT\",\"MV\",\"IE\",\"RR\",\"SPOP2\",\"PR\",\"End\"\n" };
struct DateTime
{
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
};
// 假设你有一个数据结构来存储数据
struct Data_D_file
{

    unsigned char Version;  //协议版本    0
    unsigned char DeviceLevel;//机器型号   1  
    struct DateTime  StartTime;//治疗开始时间 6  所有年份是减去2000
    struct DateTime  EndTime;//治疗结束时间 6
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
    unsigned char MinSPO2; //最小血氧 24
    unsigned char AvgSPO2; //平均血氧 25
    unsigned char MaxPR; //最大脉率 26
    unsigned char MinPR; //最小脉率 27
    unsigned short TCount; //使用时间 28 29
    unsigned short TTreat; //治疗时间 30 31
    unsigned char SN[16];  //sn号 32-47
    unsigned short SetCount; //参数修改次数48 49
};
struct stRealTimeDataType        //每分钟详细治疗数据
{
    unsigned char ucPress[600];//实时数据 100ms一次的压力和流量  
    unsigned char ucFlow[600];
    unsigned char END_FLAG;
};

int D_file_csv(void)
{
    char ch_get[1201];
    Data_D_file D_FILE_deal;
    stRealTimeDataType  ptRtData;
    const size_t numBytes = 1201; // 确保这个值大于512
    // 打开文件流
    std::ofstream file_D_DATA_csv("OUT/D_flie_data.csv");
    if (!file_D_DATA_csv.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }
    // 写入列标题
    file_D_DATA_csv << D_FILE_name;

    memset(&ch_get, 0, 1201);
    FileHandler::D_FILE_DATA.read(ch_get, 8);
    if (FileHandler::D_FILE_DATA.gcount() !=8)
    {
        std::cerr << "Failed to read the required number of bytes." << std::endl;
        return 1; // 如果没有读取到预期的字节数，退出循环
    }
    memset(&ch_get, 0, 1201);
    for (size_t tick_fila = 0; ; tick_fila++)
    {
        // 读取固定字节数到缓冲区
        FileHandler::D_FILE_DATA.read(ch_get, numBytes);
        if (FileHandler::D_FILE_DATA.gcount() != numBytes)
        {
            std::cerr << "Failed to read the required number of bytes." << std::endl;
            break; // 如果没有读取到预期的字节数，退出循环
        }

        memcpy(&ptRtData, &ch_get, 1201);
        memset(&ch_get, 0, 1201);
        if (ptRtData.END_FLAG == 0xfe)
        {
            for (size_t tick_write = 0; tick_write < 600; tick_write++)
            {
                file_D_DATA_csv << (int)ptRtData.ucPress[tick_write] << "," << (int)ptRtData.ucFlow[tick_write] \
                    << "\n";
            }
        }
        else
        {

        }
    



    }


    FileHandler::D_FILE_DATA.close(); // 关闭文件
    file_D_DATA_csv.close(); // 关闭文件
    return 1;
}