#include <iostream>
#include <filesystem>
#include <fstream>

const char* RUNLOG_TABLE_name = { "\"目录\",\"文件名\",\"大小\",\"单位\"\n" };
namespace fs = std::filesystem;
std::ofstream file_DATA_csv("./Fast_store_Release.csv");
void processFile(const fs::path& filePath) {
    // 打开文件
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        file_DATA_csv << "文件被损坏 " << filePath << "\r\n";
        return;
    }
    // 获取文件大小
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::end);
    fileSize = file.tellg() - fileSize;
    if (fileSize == 0)
    {
        file_DATA_csv << " 0 KB" << "\n";
    }
    else
    {
        file_DATA_csv << (fileSize + 1024) / 1024 << "," << "KB" << "\n";
    }

    // 关闭文件
    file.close();
}

void processDirectory(const fs::path& directoryPath)
{
    
    if (!file_DATA_csv.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }
    else
    {
        file_DATA_csv << RUNLOG_TABLE_name;
        // 检查路径是否存在且是一个目录
        if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath))
        {
            std::cerr << "路径不存在或不是一个目录: " << directoryPath << std::endl;
            return;
        }
        std::cout<< "加速存储数据分析 \r\n" ;
        // 遍历目录中的所有条目
        for (const auto& entry : fs::recursive_directory_iterator(directoryPath))
        {
            fs::path fileName_1 = entry.path().filename();
            if (entry.is_directory())
            {
                //file_DATA_csv << entry.path() << ",";
                // 递归处理子目录
                // processDirectory(entry.path());
            }
            if (entry.is_regular_file())
            {
                file_DATA_csv << entry.path() << ",";
                file_DATA_csv << fileName_1 << ",";
                processFile(entry.path());
            }
        }
    }
}

int main() {
    // 指定文件夹路径
    fs::path directoryPath = "H:/";

    // 处理指定目录
    processDirectory(directoryPath);

    return 0;
}
