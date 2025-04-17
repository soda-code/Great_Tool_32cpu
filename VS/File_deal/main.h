#pragma once
#ifndef _MAIN_ // include guard for 3rd party interop
#define _MAIN_
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
    static std::ifstream S_FILE_DATA; // 使用静态成员变量
    static bool OPEN_S_DATA_File(const std::string& filePath) {
        S_FILE_DATA.open(filePath, std::ios::binary);
        return S_FILE_DATA.is_open();
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
#define STORE_SIGNAL 0
#define STORE_DOUBLE 1
int RUN_LOG_csv(void);
int AGING_FILE_csv(void);
int S_file_csv(void);
int m_file_csv(void);
int D_file_csv(void);
int summer_csv(void);
#endif