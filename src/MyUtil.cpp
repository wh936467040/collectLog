/*********************************
 *
 * suit for windows or unix like os;
 * warning : namespace std don't use in this file 
 *
 *********************************/
#include "MyUtil.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <exception>

#ifdef __WIN32
#include <windows.h>   // <cunistd> not exist;
#else  
#include <unistd.h>
#endif


using namespace PROJECT_PUBLIC;

long MyUtil::getFileSize(std::string file)  
{
	char filename[256] = "";
	strcpy(filename,file.c_str());	
	FILE *fp=fopen(filename,"r");  
	if(!fp) return 0;  
	fseek(fp,0L,SEEK_END);  
	long size=ftell(fp);  
	fclose(fp);  
	return size;  
}


std::string MyUtil::getD5000HomePath()
{
	// try catch won't be used ,we can't catch an exception writen by c ;
	try
	{
		char path[128] = "";
		std::string res =  std::getenv("D5000_HOME");
		sprintf(path, "%s", res.c_str());
		if(path[strlen(path) - 1] == '/')
		{
			path[strlen(path)-1] = '\0';
		}
		std::string result = std::string(path);
		return result;
	}
	catch (std::exception)
	{
		return "null";
	}
}

int MyUtil::Sleep(int stime)
{
	sleep(stime);
}

std::string MyUtil::getTime(int stime)
{
	char str[128];
	struct tm *ctm;   
	time_t ts;
	int year, mon, day, hour, min, sec;
	int index = 0;
	ts = time(NULL);
	ctm = localtime(&ts);
	year = ctm->tm_year + 1900;
	mon = ctm->tm_mon + 1;
	day = ctm->tm_mday;
	hour = ctm->tm_hour;
	min = ctm->tm_min;
	sec = ctm->tm_sec;
	sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d", year, mon, day, hour, min, sec);
	 
	if(sec <= stime)
	{
		index = sec;
		sec = stime;
		sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d", year, mon, day, hour, min, sec);
		//std::cout << "sleep time :" <<stime<<" -  "<<index <<"  =  "<<stime - index << std::endl;
		Sleep(stime - index);
	}
	else
	{
		Sleep(60 - sec);
		//std::cout << "sleep time :" << 60 - sec << std::endl;
		ts = time(NULL);
		ctm = localtime(&ts);   
		year = ctm->tm_year + 1900;
		mon = ctm->tm_mon + 1;
		day = ctm->tm_mday;
		hour = ctm->tm_hour;
		min = ctm->tm_min;
		sec = ctm->tm_sec;
		sprintf(str, "%04d-%02d-%02d %02d:%02d:%02d", year, mon, day, hour, min, sec);
	}

	return std::string(str);
}                                             													                         
std::string MyUtil::itos(int i)
{
        char tmp[16]="";
        sprintf(tmp,"%d",i);
        return std::string(tmp);
}

std::string MyUtil::ltos(long l)
{
        char tmp[64]="";
        sprintf(tmp,"%ld",l);
        return std::string(tmp);
}

std::string MyUtil::f2tos(float f)
{
        char tmp[64]="";
        sprintf(tmp,"%.2f",f);
        return std::string(tmp);
}

std::string MyUtil::replaceAll(std::string str,std::string oldValue,std::string newValue)
{
	for(std::string::size_type pos(0); pos != std::string::npos; pos += newValue.length())  
       	{     
		if((pos=str.find(oldValue,pos)) != std::string::npos)     str.replace(pos,oldValue.length(),newValue);     
		else   break;     
	}     
	return   str;
}

