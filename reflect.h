#include <vector>
#include <iostream>
#include <string>
#include <cstddef>

namespace reflect {
	struct TypeDescriptor{
		const char* name;
		size_t size;

		TypeDescriptor(const char* name,size_t size):name{name},size{size} {}
		virtual ~TypeDescriptor(){}
		virtual std::string getFullName() const { return name; }
		virtual void dump(const void* obj, int indentLevel = 0)const = 0;
	};

}	//	namespace reflect
