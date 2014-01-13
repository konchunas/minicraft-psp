#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <oslib/VirtualFile.h>

using namespace std;

class Logger
{
public:
	static void init();
	static void log(char* msg);
	static void log(const char * msg, int number);

private:
	static VIRTUAL_FILE * logFile;
};

#endif /* LOGGER_H_ */
