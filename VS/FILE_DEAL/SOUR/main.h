#pragma once
#ifndef _MAIN // include guard for 3rd party interop
#define _MAIN

#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdio.h> 
#include <vector>
#include <string>

class FileHandler {
public:
    static std::ifstream FILE_AGING_LOG; // 使用静态成员变量
    static bool OPEN_AGING_File(const std::string& filePath) {
        FILE_AGING_LOG.open(filePath, std::ios::binary);
        return FILE_AGING_LOG.is_open();
    }
    static std::ifstream SUMMER_DATA; // 使用静态成员变量
    static bool OPEN_SUMMER_File(const std::string& filePath) {
        SUMMER_DATA.open(filePath, std::ios::binary);
        return SUMMER_DATA.is_open();
    }

    static std::ifstream M_FILE_DATA; // 使用静态成员变量
    static bool OPEN_M_DATA_File(const std::string& filePath) {
        M_FILE_DATA.open(filePath, std::ios::binary);
        return M_FILE_DATA.is_open();
    }
    static std::ifstream D_FILE_DATA; // 使用静态成员变量
    static bool OPEN_D_DATA_File(const std::string& filePath) {
        D_FILE_DATA.open(filePath, std::ios::binary);
        return D_FILE_DATA.is_open();
    }
    static std::ifstream RUN_LOG;
    static bool OPEN_RUN_LOG_File(const std::string& filePath) {
        RUN_LOG.open(filePath, std::ios::binary);
        return RUN_LOG.is_open();
    }

};
// 假设你有一个数据结构来存储数据
struct Data_relog {
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

int RUN_LOG_csv(void);
int AGING_FILE_csv(void);
int m_file_csv(void);
int D_file_csv(void);
int summer_csv(void);
#endif