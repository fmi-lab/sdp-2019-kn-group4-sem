#include <string>
#include <fstream>
#include <iostream>
#include "FileExplorer.h"

void FileExplorer::open(std::string filepath)
{
    if (currentFile.is_open())
    {
        currentFile.close();
        previous.push(currentPath);
    }
    clearNext();
    currentFile.open(filepath.c_str());
    currentPath = filepath;
    more();
}
void FileExplorer::more()
{
    std::string line;
    int linesRead = 0;
    for (; linesRead < 10 && std::getline(currentFile, line); linesRead++)
    {
        std::cout << line << std::endl;
    }
    if (currentFile.eof())
    {
        std::cout << "EOF Reached" << std::endl;
    }
}

void FileExplorer::clearNext()
{
    while(!next.empty())
    {
        next.pop();
    }
}

void FileExplorer::goBack()
{
    next.push(currentPath);
    std::string previousPath = previous.top();
    previous.pop();
    open(previousPath);

}
void FileExplorer::goForward()
{
    // TODO
}
