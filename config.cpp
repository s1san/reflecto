#include <fstream>
#include <cstdlib>

#include "config.h"

namespace config
{
	bool Config::IsSpace(char c)
	{
		if (c == ' ' || c == '\t')
			return true;
		return false;
	}

	bool Config::IsCommentChar(char c)
	{
		if (c == '#')
			return true;
		return false;
	}

	void Config::Trim(std::string& str)
	{
		if (str.empty())
			return;
		int i, start_pos, end_pos;
		for (i = 0; i < str.size(); i++)
		{
			if (!IsSpace(str[i]))
				break;
		}

		if (i == str.size())
		{
			str = "";
			return;
		}

		start_pos = i;
		for (i = str.size() - 1; i >= 0; i--)
		{
			if (!IsSpace(str[i]))
				break;
		}
		end_pos = i;
		str = str.substr(start_pos, end_pos - start_pos + 1);
	}

	bool Config::AnalyseLine(const std::string& line, std::string& section, std::string& key, std::string& value)
	{
		if (line.empty())
			return false;
		int start_pos = 0, end_pos = line.size() - 1, pos, s_startpos, e_endpos;
		if ((pos = line.find("#")) != -1)
		{
			if (pos == 0)
				return false;
			end_pos = pos - 1;
		}
		if ((s_startpos = line.find("[")) != -1 && (e_endpos = line.find("]")) != -1)
		{
			section = line.substr(s_startpos + 1, e_endpos - 1);
			return true;
		}
		std::string new_line = line.substr(s_startpos, start_pos + 1 - end_pos);
		if ((pos = new_line.find('=')) == -1)
			return false;
		key = new_line.substr(0, pos);
		value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1));
		Trim(key);
		if (key.empty())
			return false;
		Trim(value);
		if ((pos = value.find("\r")) > 0)
		{
			value.replace(pos, 1, "");
		}
		if ((pos = value.find("\n")) > 0)
		{
			value.replace(pos, 1, "");
		}
		
		return true;
	}
}