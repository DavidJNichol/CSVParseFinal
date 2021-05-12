#include "CSVParser.h"
#include <cassert>

int riskOneCount = 0;

int riskTwoCount = 0;

int riskThreeCount = 0;

std::vector<std::string> *ParseFile(const std::string &path) 
{
	std::fstream fileStream;

	// not sure why I need to use c_str for this. Maybe because path is a ref?
	fileStream.open(path.c_str(), std::ios::in); 

	assert(fileStream.is_open()); // assert that fstream open worked

	std::string line;

	std::vector<std::string> *lines = new std::vector<std::string>();	

    int index = 0;
	while (getline(fileStream, line)) // parsing into string happens here until filestream is empty
    {		
		lines->push_back(line); // add the next line into vector	
        index++;
	}

	return lines;
}

int FindStringInCSV(std::vector<std::string> *a, std::string searchWord)
{
	int searchWordSize = searchWord.size();

    int count = 0;

    for (std::vector<std::string>::iterator iter = a->begin(); iter != a->end(); ++iter) 
    {
        for (size_t pos = 0; pos < (*iter).length(); pos += searchWordSize) 
        {
            pos = (*iter).find(searchWord, pos);

            if (pos != std::string::npos) 
                ++count;                
            else break;
        }
    }


    std::cout << searchWord + " Count:" << count << std::endl;
    return count;
}

int main()
{
	std::vector<std::string> *a = ParseFile("/home/cuser/Desktop/CSVParseFinal/Food_Inspections.csv");
    
    assert(a->size() == 219702); // num lines in food_inspections

    assert(FindStringInCSV(a, "Risk 1 (High)") == 157553);

    assert(FindStringInCSV(a, "Risk 2 (Medium)") == 42602);

    assert(FindStringInCSV(a, "Risk 3 (Low)") == 19439);
    
    delete(a);
    return 0;
}

