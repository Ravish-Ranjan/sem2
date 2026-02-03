#ifndef SPLIITSTRING_CPP
#define SPLIITSTRING_CPP
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string inp,char sep = ' '){   
    std::stringstream ss(inp);
    std::string segment;
    std::vector<std::string> results;
    
    while (std::getline(ss, segment, sep)) {
        results.push_back(segment);
    }
    return results;
}
    


#endif