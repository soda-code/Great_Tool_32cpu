#include "main.h"

struct DataItem {
    int ExPanTemp;
    int adc_temp;
    int EXHeatPanPWM;
    int reg;
};

const char* Table_name_aging = { "\"ExPanTemp\",\"Adc_temp\",\"EXHeatPanPWM\",\n" };
int AGING_FILE_csv(void)
{
    char ch_get[6];
    const size_t numBytes = 6;
    // 打开文件流
    std::ofstream laohua_csv("OUT/laohua_data.csv");
    if (!laohua_csv.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }
    laohua_csv << Table_name_aging;    // 写入列标题


    // 逐字符读取文件内容

    uint16_t temp_data[3] = { 0 };
    long tick_fila = 0;
    for (size_t i = 0; ; ++i)
    {
        // 读取固定字节数到缓冲区
        FileHandler::FILE_AGING_LOG.read(ch_get, numBytes);
        if (FileHandler::FILE_AGING_LOG.gcount() != numBytes)
        {
            std::cerr << "Failed to read the required number of bytes." << std::endl;
            break; // 如果没有读取到预期的字节数，退出循环
        }
        // 处理读取到的数据
#if 1
        temp_data[0] = ((uint16_t)ch_get[1] << 8) | (uint8_t)ch_get[0];
        temp_data[1] = ((uint16_t)ch_get[3] << 8) | (uint8_t)ch_get[2];
        temp_data[2] = ((uint16_t)ch_get[5] << 8) | (uint8_t)ch_get[4];
#endif
        memset(&ch_get, 0, sizeof(ch_get));
        laohua_csv << temp_data[0] << "," << temp_data[1] << "," << temp_data[2] << "," <<"\n";
    
    }

    FileHandler::FILE_AGING_LOG.close(); // 关闭文件
    laohua_csv.close(); // 关闭文件
    return 1;
}
