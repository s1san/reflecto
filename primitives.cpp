#include "reflect.h"

namespace reflect {
	struct TypeDescriptor_Int :TypeDescriptor {
		TypeDescriptor_Int() :TypeDescriptor{ "int",sizeof(int) } {
		}
		virtual void dump(const void* obj,int )const override{
			std::cout << "int{" << *(const int*)obj << "}";
		}
	};

}