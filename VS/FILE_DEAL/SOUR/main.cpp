#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdio.h> 
#include <vector>
#include <string>
#include "main.h"

std::string filePath = "OUT/laohua.bys"; // 替换为你的文件路径
std::ifstream FileHandler::FILE_AGING_LOG; // 定义静态成员变量

std::string filePath1 = "OUT/summer.bys"; // 替换为你的文件路径
std::ifstream FileHandler::SUMMER_DATA; // 定义静态成员变量

std::string M_FILE_PATH = "OUT/0100040m.bys"; // 替换为你的文件路径
std::ifstream FileHandler::M_FILE_DATA; // 定义静态成员变量

std::string D_FILE_PATH = "OUT/0100002d.bys"; // 替换为你的文件路径
std::ifstream FileHandler::D_FILE_DATA; // 定义静态成员变量

std::string RUN_LOG_PATH = "OUT/RunLog.bys"; // 替换为你的文件路径
std::ifstream FileHandler::RUN_LOG; // 定义静态成员变量

int return_get;
namespace fs = std::filesystem;
int main()
{
    // ... 更多数据

    if (FileHandler::OPEN_AGING_File(filePath))
    {
        AGING_FILE_csv();
    }
    if (FileHandler::OPEN_SUMMER_File(filePath1))
    {
        summer_csv();
    }
  
    if (FileHandler::OPEN_RUN_LOG_File(RUN_LOG_PATH))
    {
        RUN_LOG_csv();
    }
# if 0
    if (FileHandler::OPEN_M_DATA_File(filePath2))
    {
        m_file_csv();
    }
#endif

    else
    {
        fs::path dir_path = "OUT";  // 替换为实际的目录路径
        std::string str1  = "OUT/";  // 替换为实际的目录路径
        if (fs::exists(dir_path) && fs::is_directory(dir_path)) 
        {
            for (const auto& entry : fs::directory_iterator(dir_path)) 
            {
                str1.clear();
                str1 += "OUT/";
                if (!(fs::is_regular_file(entry)))
                {
                    break;
                }

                std::string filename = entry.path().filename().string();
                // 查找文件扩展名的位置
                size_t dot_pos = filename.rfind('.');
                // 如果找到了扩展名且扩展名长度大于1
                if (dot_pos != std::string::npos && dot_pos < filename.size() - 1)
                {
                    std::string extension = filename.substr(dot_pos + 1);  // 获取扩展名

                    if (extension == "csv")
                    {
                        continue;
                    }
                    if ((extension.size() > 1)&&(filename.size()>extension.size()&&(filename.size()>5)))
                    {
                        std::cout<< filename[filename.size() - extension.size()-2] << std::endl;  // 获取扩展名倒数第二个字符
                        if (filename[filename.size() - extension.size() - 2] == 'm')
                        {
                            str1 += filename;
                            M_FILE_PATH = str1;
                            if (FileHandler::OPEN_M_DATA_File(M_FILE_PATH))
                            {
                                return_get= m_file_csv();
                            }
                        }
                        if (filename[filename.size() - extension.size() - 2] == 'd')
                        {
                            str1 += filename;
                            D_FILE_PATH = str1;
                            //memcpy(&D_FILE_PATH, &str1, sizeof(D_FILE_PATH));
                            if (FileHandler::OPEN_D_DATA_File(D_FILE_PATH))
                            {
                                return_get = D_file_csv();
                            }
                        }
                    }
                    else
                    {
                        return 0;  // 如果文件名太短，返回空字符
                    }
                }
            }
        }
        else
        {
            std::cerr << "Directory does not exist or is not a valid directory." << std::endl;
        }
        std::cerr << "Failed to open the file: " << filePath << std::endl;
        return 1;
    }

    return 0;
}