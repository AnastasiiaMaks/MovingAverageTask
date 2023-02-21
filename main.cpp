#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include <chrono>


std::vector<double> generate_data_double(int data_length)
// generates vector of double 
{
	std::vector<double> data;
	for(int i = 0; i < data_length; i++)
	{
		data.push_back(rand());
	}
	return data;
}

std::vector<float> generate_data_float(int data_length)
// generates vector of float 
{
	std::vector<float> data;
	for(int i = 0; i < data_length; i++)
	{
		data.push_back(rand());
	}
	return data;
}

std::vector<float> moving_average_float(std::vector<float> &data, int window_size)
// calculates vector of moving average float 
{
	std::vector<float> mov_aver;

	// write first value
	mov_aver.push_back(data[0]);

	for(int i = 1; i < data.size(); i++)
	{	
		// start case 
		if((i - window_size)<0)
		{
			mov_aver.push_back(std::accumulate(data.cbegin(), data.cbegin() + i + 1, 0)/(i+1));
		} else
		// main case
		{
			mov_aver.push_back(std::accumulate(data.cbegin() + (i - window_size + 1), data.cbegin() + i + 1, 0)/window_size);
		}		
	}
	return mov_aver;
}

std::vector<double> moving_average_double(std::vector<double> &data, int window_size)
// calculates vector of moving average double 
{
	std::vector<double> mov_aver;

	// write first value
	mov_aver.push_back(data[0]);

	for(int i = 1; i < data.size(); i++)
	{	
		// start case 
		if((i - window_size)<0)
		{
			mov_aver.push_back(std::accumulate(data.cbegin(), data.cbegin() + i + 1, 0)/(i + 1));
		} else
		// main case
		{
			mov_aver.push_back(std::accumulate(data.cbegin() + (i - window_size + 1), data.cbegin() + i + 1, 0)/window_size);
		}		
	}
	return mov_aver;
}


int main()
{
	// inter initial data
	int data_length;        // data array length	
	int window_size;        // window size
	std::cout << "Inter length of data: " << std::endl;
	std::cin >> data_length ;
	std::cout << "Inter length of window: " << std::endl;
	std::cin >> window_size;

	// starting point
	srand(std::time(NULL));

	// create data arrays
	std::vector<float> data_float;
	data_float = generate_data_float(data_length);
	std::vector<double> data_double;
	data_double = generate_data_double(data_length);
		
	// start time measuring 1
	auto t_start = std::chrono::steady_clock::now();

	// calculate moving average float
	std::vector<float> moving_average_f = moving_average_float(data_float, window_size);
	
	// calculate time 1
	auto dt = std::chrono::steady_clock::now() - t_start;
	double time_float = std::chrono::duration_cast<std::chrono::microseconds>(dt).count();

	// calculate perfomance for float
	double perf_float = data_length/time_float;
      std::cout << "Perfomance for FLOAT type: " << perf_float*1000000 << " ticks per seconds" << std::endl;

	// start time measuring 2
	t_start = std::chrono::steady_clock::now();

	// calculate moving average double
	std::vector<double> moving_average_d = moving_average_double(data_double, window_size);
	
	// calculate time 2
	dt = std::chrono::steady_clock::now() - t_start;
      double time_double = std::chrono::duration_cast<std::chrono::microseconds>(dt).count();

	// calculate perfomance for double
	double perf_double = data_length/time_double;
      std::cout << "Perfomance for DOUBLE type: " << perf_double*1000000 << " ticks per seconds" << std::endl;	

	return 0;
}
