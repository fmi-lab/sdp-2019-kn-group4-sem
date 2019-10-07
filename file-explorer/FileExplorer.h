#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <fstream>
#include <string>
#include <stack>
class FileExplorer
{
    public:
        void open(std::string filepath);
        void more();
        void goBack();
        void goForward();
    protected:

    private:
        std::ifstream currentFile;
        std::string currentPath;
        std::stack<std::string> previous;
        std::stack<std::string> next;

        void clearNext();
};

#endif // FILEEXPLORER_H
