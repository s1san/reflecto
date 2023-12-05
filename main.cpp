#include <vector>
#include "reflect.h"

struct Node
{
	std::string key;
	int value;
	std::vector<Node> children;

	REFLECT()
};

int main()
{

}

