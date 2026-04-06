#include <list>
#include <string>

std::list<int> inputFromConsole();
std::list<int> inputFromFile(const std::string& filename);
std::list<int> inputRandom();
std::list<int> getList();
void printList(std::list<int>& L);