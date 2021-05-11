#include "CSVParser.h"
#include <cassert>

std::vector<std::string> ParseFile(const std::string &path) 
{
	std::fstream fileStream;

	// not sure why I need to use c_str for this. Maybe because path is a ref?
	fileStream.open(path.c_str(), std::ios::in); 

	assert(fileStream.is_open()); // assert that fstream open worked

	std::string line;

	std::vector<std::string> lines = std::vector<std::string>();		

	while (getline(fileStream, line)) // parsing into string happens here until filestream is empty
    {		
		lines.push_back(line); // add the next line into vector	
	}

	return lines;
}

int FindStringInCSV(std::string &csv, std::string &subString)
{
	int csvLength = csv.size();

	int subStringLength = subString.length();
	
	int res = 0;

	/* A loop to slide pat[] one by one */
    for (int i = 0; i <= subStringLength - csvLength; i++)
    {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < csvLength; j++)
            if (subString[i+j] != csv[j])
                break;
  
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == csvLength) 
        {
           res++;
           j = 0;
        }
    }
    return res;
}

int main()
{
	std::string a = ParseFile("/home/cuser/Desktop/CSVFinal/food.csv").at(6);
    std::string txt = "dhimanman";
    std::string pat = "man";
    std::cout << a <<std::endl;
    return 0;
}