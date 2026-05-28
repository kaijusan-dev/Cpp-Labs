#include <string>
#include <vector>

std::vector<int> inputIntVectorFromConsole();
std::vector<int> inputIntVectorFromFile(const std::string& filename);
std::vector<int> inputIntVectorRandom();
std::vector<int> getIntVector();
std::vector<std::vector<int>> getIntVectors();
void printIntVector(std::vector<int>& V);
void printIntVectors(std::vector<std::vector<int>>& vectors);

std::vector<std::string> inputStringVectorFromConsole();
std::vector<std::string> inputStringVectorFromFile(const std::string& filename);
std::vector<std::string> inputStringVectorRandom();
std::vector<std::string> getStringVector();
std::vector<std::vector<std::string>> getStringVectors();
void printStringVector(std::vector<std::string>& V);
void printStringVectors(std::vector<std::vector<std::string>>& vectors);