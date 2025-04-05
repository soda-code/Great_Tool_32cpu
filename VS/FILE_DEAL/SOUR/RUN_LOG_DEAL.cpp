#include "main.h"
const char* RUNLOG_TABLE_name = { "\"start_time\",\"Error\",\"MODE\",\"G_PDM\",\"MOTOR_PWM\",\"LO_speed\"\n" };


Data_Run_log RUNLOG_Data;
int RUN_LOG_csv(void)
{
    // 获取文件大小
    const size_t numBytes = 100; // 确保这个值大于512
    char ch_get[100];

    std::ofstream File_RUNLOG_csv("OUT/RUNLOG_data.csv");
    if (!File_RUNLOG_csv.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
        return 1;
    }
    File_RUNLOG_csv << RUNLOG_TABLE_name;
    for (size_t i = 0; ; ++i) 
    {
        // 读取固定字节数到缓冲区
        FileHandler::RUN_LOG.read(ch_get, numBytes);
        if (FileHandler::RUN_LOG.gcount() != numBytes)
        {
            std::cerr << "Failed to read the required number of bytes." << std::endl;
            break; // 如果没有读取到预期的字节数，退出循环
        }
        // 处理读取到的数据

        memcpy(&RUNLOG_Data, &ch_get, 100);
        memset(&ch_get, 0, 100);
#if 1
        File_RUNLOG_csv << (int)RUNLOG_Data.start_year << "-" << (int)RUNLOG_Data.start_month << "-" << (int)RUNLOG_Data.start_day << " "\
            << (int)RUNLOG_Data.start_hour << ":" << (int)RUNLOG_Data.start_min << ":" << (int)RUNLOG_Data.start_sec << ","\
            << "0X" << std::hex <<(((int)RUNLOG_Data.error_flag_32<<24)|((int)RUNLOG_Data.error_flag_24<<16)|((int)RUNLOG_Data.error_flag_16<<8)| (int)RUNLOG_Data.error_flag_8 )<< "," \
            << std::dec <<((int)RUNLOG_Data.PARAMETER_MODE) << "," \
            << ((int)RUNLOG_Data.g_bpm) << "," \
            << ((int)RUNLOG_Data.MOTOR_PWM_work_H<<8|(int)RUNLOG_Data.MOTOR_PWM_work_L ) << "," \
            << ((int)RUNLOG_Data.LO_speed_H << 8 | (int)RUNLOG_Data.LO_speed_L) << "," \
            << "\n";
#endif
    }

    FileHandler::RUN_LOG.close(); // 关闭文件
    File_RUNLOG_csv.close(); // 关闭文件
    return 1;
}