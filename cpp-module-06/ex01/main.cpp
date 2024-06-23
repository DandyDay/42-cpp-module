#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data *data = new Data();
	data->i = 42;
	data->f = 42.4242;
	data->d = 42.42424242424242424242424242424242;
	data->p = data;
	data->c = 'f';

	std::cout << "data: " << std::endl;
	std::cout << "\ti: " << data->i << std::endl;
	std::cout << "\tf: " << data->f << std::endl;
	std::cout << "\td: " << data->d << std::endl;
	std::cout << "\tp: " << data->p << std::endl;
	std::cout << "\tc: " << data->c << std::endl;
	std::cout << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	std::cout << "ptr: " << std::hex << ptr << std::dec << std::endl;
	std::cout << std::endl;

	Data *data2 = Serializer::deserialize(ptr);

	std::cout << "data2: " << std::endl;
	std::cout << "\ti: " << data2->i << std::endl;
	std::cout << "\tf: " << data2->f << std::endl;
	std::cout << "\td: " << data2->d << std::endl;
	std::cout << "\tp: " << data2->p << std::endl;
	std::cout << "\tc: " << data2->c << std::endl;
	std::cout << std::endl;

	return 0;
}
