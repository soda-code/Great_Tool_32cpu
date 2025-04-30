#include "crc.h"



typedef struct
{
	uint32_t info_len;        //信息长度
	char     hd_version[4];   //硬件版本号
	char     fw_version[4];   //软件版本号
	uint32_t bin_size;        //bin文件大小
	uint32_t start_addr;      //起始地址
	uint32_t create_time;	  //创建时间
	char     custom_data[36]; //用户自定义区
	uint32_t crc_code;		  //crc校验结果


}update_head_info_t;


// CRC32计算函数
uint32_t crc32(const uint8_t* data, size_t length) 
{
	static uint32_t crcTable[256];
	if (crcTable[1] == 0) {
		// 初始化CRC表
		for (uint32_t i = 0; i < 256; i++) {
			uint32_t crc = i;
			for (uint32_t j = 8; j != 0; j--) {
				if (crc & 1)
					crc = (crc >> 1) ^ 0xedb88320;
				else
					crc >>= 1;
			}
			crcTable[i] = crc;
		}
	}
	uint32_t crc = 0xffffffff;
	for (size_t k = 0; k < length; k++) {
		crc = (crc >> 8) ^ crcTable[(crc & 0xff) ^ *data++];
	}
	return crc ^ 0xffffffff;
}

update_head_info_t bin_head = { 0 };

bool addBytesToFile(const std::string& originalFilePath, const std::string& newFilePath, const std::vector<uint8_t>& bytesToAdd)
{
	std::ifstream originalFile(originalFilePath, std::ios::binary);
	if (!originalFile) 
	{
		std::cerr << "Failed to open the original file." << std::endl;
		return false;
	}

	// 读取原始文件内容
	std::vector<uint8_t> originalData((std::istreambuf_iterator<char>(originalFile)), std::istreambuf_iterator<char>());
	originalFile.close();

	// 创建新文件并写入新字节和原始数据
	std::ofstream newFile(newFilePath, std::ios::binary);
	if (!newFile) {
		std::cerr << "Failed to create the new file." << std::endl;
		return false;
	}

	// 写入要添加的字节
	newFile.write(reinterpret_cast<const char*>(&bin_head), sizeof(bin_head));

	// 写入原始文件内容
	newFile.write(reinterpret_cast<const char*>(originalData.data()), originalData.size());
	newFile.close();

	return true;
}



std::vector<uint8_t> bytesToAdd = { 0 }; // 要添加的字节
uint16_t add_num = 0;
uint8_t add_table[64] = { 0 };
const char* binFilePath[2] = { "./MDK-ARM/Output/YH680_H5.bin","./MDK-ARM/Output/ETBLK_H562.bin" }; // BIN文件路径
const char* binFilePath_out[2] = { "./MDK-ARM/YW_BC3_YH-680_S1.X.XX.A250324.bin",\
							   "./MDK-ARM/YW_ET6_Elite_V1.0.00.XXXXXXX.bin" }; // BIN文件路径


uint8_t CRC_DEAL(void)
{
	uint8_t error_flag[2] = {0};

	std::vector<uint8_t> fileData;
	FILE* file;
	error_flag[0] = fopen_s(&file, binFilePath[0], "rb");
	error_flag[1] = fopen_s(&file, binFilePath[1], "rb");
	Add_Crc(error_flag);
	if (error_flag) 
	{
		std::cerr << "Failed to open file: " << binFilePath[0] << std::endl;
		return 1;
	}
	// 读取文件到内存
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);
	fileData.resize(fileSize);
	fread(fileData.data(), 1, fileSize, file);
	fclose(file);
	//************************** 计算CRC32
	uint32_t crc = crc32(fileData.data(), fileData.size());
	//********************获取要添加的字符

	bin_head.info_len = 64;
	bin_head.bin_size = fileSize;
	bin_head.start_addr = 0;
	bin_head.create_time = 0;
	bin_head.crc_code = crc;
	memset(bin_head.custom_data, 0, sizeof(bin_head.custom_data));
	memset(bin_head.hd_version, 0, sizeof(bin_head.hd_version));
	memset(bin_head.fw_version, 0, sizeof(bin_head.fw_version));

	addBytesToFile(binFilePath[0], binFilePath_out[1], bytesToAdd);


}
