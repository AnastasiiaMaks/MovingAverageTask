#include <iostream>
#include <vector>
#include <ctime>

std::vector<double> generate_data_double(int data_length)
// generates vector of double 
{
	std::vector<double> data;
	for(int i=0; i < data_length; i++)
	{
		data.push_back(rand());
	}
	return data;
}

std::vector<float> generate_data_float(int data_length)
// generates vector of float 
{
	std::vector<float> data;
	for(int i=0; i < data_length; i++)
	{
		data.push_back(rand());
	}
	return data;
}


int main()
{
	// inter initial data
	int data_length;
	std::cout << "Inter length of data: " << std::endl;
	std::cin >> data_length ;

	// starting point
	srand(std::time(NULL));

	// create data arrays
	std::vector<float> data_float;
	data_float = generate_data_float(data_length);
	std::vector<double> data_double;
	data_double = generate_data_double(data_length);

	// show 
	std::cout << "Generated data float: " << std::endl;
	for(int i=0; i < data_length; i++)
	{
		std::cout << data_float[i] << std::endl;
	}	

	std::cout << "Generated data double: " << std::endl;
	for(int i=0; i < data_length; i++)
	{
		std::cout << data_double[i] << std::endl;
	}

	return 0;
}
