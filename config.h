#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <string>
#include <map>

namespace config 
{
	class Config
	{
	public:
		Config()
		{

		}
		~Config()
		{

		}
		bool		ReadConfig(const std::string& filename);
		int			ReadInt	  (const char* section, const char* item, const int& defualt_value);
		float		ReadFloat (const char* section, const char* item, const float& defualt_value);
		std::string ReadString(const char* section, const char* item, const char* defualt_value);
	private:
		bool IsSpace(char c);
		bool IsCommentChar(char c);
		void Trim(std::string& str);
		bool AnalyseLine(const std::string& line, std::string& section, std::string& key, std::string& value);
	private:
		std::map<std::string, std::map<std::string, std::string>>settings_;
	};
}

#endif