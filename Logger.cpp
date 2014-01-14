#include "Logger.h"

VIRTUAL_FILE * Logger::logFile;

void Logger::init()
{
	Logger::logFile = VirtualFileOpen((char*)"host0:/log.txt", 0, VF_FILE, VF_O_WRITE);
}

void Logger::log(char * msg)
{
	char str[255];
	sprintf(str, "%s\n",msg);
	VirtualFilePuts(str, logFile);
	 //VirtualFilePuts(msg, logFile);
	 //VirtualFilePuts("\n", logFile);
}

void Logger::log(const char * msg, int number)
{
	char str[255];
	sprintf(str, "%s %d\n", msg, number);
	VirtualFilePuts(str, logFile);
}
