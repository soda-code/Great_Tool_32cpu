#include "main.h"
const char* RUNLOG_TABLE_name = { "\"start_time\",\"Error\",\"MODE\",\"G_PDM\",\"MOTOR_PWM\",\"LO_speed\"\n" };
// 假设你有一个数据结构来存储数据
struct Data_Run_log {
    uint8_t START_1;
    uint8_t START_2;
    uint8_t start_year;
    uint8_t start_month;
    uint8_t start_day;
    uint8_t start_hour;
    uint8_t start_min;
    uint8_t start_sec;
    uint8_t error_flag_32;
    uint8_t error_flag_24;
    uint8_t error_flag_16;
    uint8_t error_flag_8;
    uint8_t reg1[4];
    uint8_t PARAMETER_MODE;
    uint8_t reg2[8];
    uint8_t PARAMETER_CPAP_THEAPY_H;
    uint8_t PARAMETER_CPAP_THEAPY_L;
    uint8_t PARAMETER_CPAP_APA_START_H;
    uint8_t PARAMETER_CPAP_APA_START_L;
    uint8_t reg3[3];
    uint8_t g_bpm;
    uint8_t reg4[3];
    uint8_t PARAMETER_RAMP;
    uint8_t reg5[1];
    uint8_t PARAMETER_HUMIDITY;
    uint8_t PARAMETER_APAP_MAX_PRESS;
    uint8_t PARAMETER_APAP_MIN_PRESS;
    uint8_t reg6[4];
    uint8_t g_PressureLF_H;
    uint8_t g_PressureLF_L;
    uint8_t FlowLF;
    uint8_t g_Flow_Leak;
    uint8_t g_bpm_1;
    uint8_t reg7[5];
    uint8_t u_SPo2;
    uint8_t u_Bpm;
    uint8_t reg8[4];
    uint8_t adc_press_H;
    uint8_t adc_press_L;
    uint8_t Flow_Orig_Signal_H;
    uint8_t Flow_Orig_Signal_L;
    uint8_t MOTOR_PWM_work_H;
    uint8_t MOTOR_PWM_work_L;
    uint8_t LO_speed_H;
    uint8_t LO_speed_L;
    uint8_t reg9[3];
    uint8_t ExPanTemp;
    uint8_t adc_temp_H;
    uint8_t adc_temp_L;
    uint8_t EXHeatPanPWM_H;
    uint8_t EXHeatPanPWM_L;
    uint8_t adc_pipe_H;
    uint8_t adc_pipe_L;
    uint8_t ExPipeTemp;
    uint8_t adc_pipe1_H;
    uint8_t adc_pipe1_L;
    uint8_t ExPipePWM_H;
    uint8_t ExPipePWM_L;
    uint8_t reg10[6];
    uint8_t PARAMETER_FAN_RUN_TIME_32;
    uint8_t PARAMETER_FAN_RUN_TIME_24;
    uint8_t PARAMETER_FAN_RUN_TIME_16;
    uint8_t PARAMETER_FAN_RUN_TIME_8;
    uint8_t reg11[4];
    uint8_t ADD_SUM;
    uint8_t END;
};
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