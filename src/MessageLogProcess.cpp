/***********************************
 *  
 * class MessageLogProcess 
 * extend from LogProcess.class
 * author:wanghao200911@163.com
 * date: 2018-01-04
 *
 **********************************/

#include "MessageLogProcess.h"
#include "LogProcess.h"
#include "LogFilter.h"
#include "MyUtil.h"
#include "Parameter.h"
#include "MySendFactory.h"

#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

using namespace MONITOR_LOG;
using namespace PROJECT_PUBLIC;

MessageLogProcess::MessageLogProcess(string fileName,string fileName0,LogFilter * filter)
{
	mFileName = fileName;
	mFileName0 = fileName0;
	mFilter = filter;
}

int MessageLogProcess::run()
{
	cout << "begin read message log and use info above:"<< endl;
	cout << "read messages path:" << mFileName << endl;
	cout << "read messages.0(if exist) path:" << mFileName0 << endl;
	mFilter -> print();
	long readLen = MyUtil::getFileSize(mFileName);
	while(1)
	{       
		long fileLen = MyUtil::getFileSize(mFileName);
		if(readLen > fileLen)
		{
			cout << "warning: messages has changed because of crontab" << endl;
			//readFile(mFileName0,readLen);  // read messages.0 if exist;
			readLen =0;
		}
		//readLen = readFile(mFileName,0);   // warning : test;
		readLen = readFile(mFileName,readLen);
		MyUtil::Sleep(Parameter::sleepTime);
	}
	return 1;
}

long MessageLogProcess::readFile(const string fileName,const long startPointer)
{
	cout << "start read log messages from " << startPointer << endl;
	long fileLen = startPointer;
	FILE *fp;
	char buf[2048] = "";
	fp=fopen(fileName.c_str(),"r");
	if(fp==NULL)
	{
		cout<<"open " << fileName.c_str() <<  " failed!"<<endl;
		return 0;
	}
	fseek(fp,fileLen,SEEK_SET);
	vector<string> vecStr;
	string sendStr = "log:";
	int sendCount = 0;
	while(fgets(buf,2048,fp) != NULL)
	{
		string str = string(buf);
		int regexNo  = (this -> mFilter)-> process(str);
		if(regexNo > 0 )
		{
			//cout << str << endl;
			str = MyUtil::replaceAll(str,";",",");
			str = MyUtil::replaceAll(str,"\"","\'");
			str = MyUtil::replaceAll(str,">","&IT,");
			str = MyUtil::replaceAll(str,"<","&IT,=");
			if(sendCount == 0)
			{
				sendStr = sendStr + str;
			}
			else
			{
				sendStr = sendStr + ";" + str;
			}
			sendCount ++ ;
			//cout << regexNo << "  " << str << endl;
			if(sendCount == 10)
			{
				  vecStr.push_back(sendStr);
				  MySendFactory::sendInfo -> sendAllInfo("11001",Parameter::nodeId,MyUtil::getTime(Parameter::sleepTime),vecStr);
				  sendStr = "log:";
				  vecStr.clear();
				  sendCount = 0;
			}
		}
		memset(buf,0,sizeof(buf));
	}
	cout << sendStr << endl;
	if(sendCount != 0)
	{
		vecStr.push_back(sendStr);
		MySendFactory::sendInfo -> sendAllInfo("11001",Parameter::nodeId,MyUtil::getTime(Parameter::sleepTime),vecStr);
	}
	fileLen=ftell(fp);
	fclose(fp);
	cout << "end read log messages end to " << fileLen << endl;
	return fileLen;
}
