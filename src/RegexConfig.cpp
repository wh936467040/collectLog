/****************************
file: Parameter.cpp
author: wanghao200911@163.com
date: 2017-07-14
version:1.0
****************************/
#include "RegexConfig.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
using namespace MONITOR_LOG;

string RegexConfig :: configFile = "";
map<int,string> RegexConfig :: regexChain;

RegexConfig::RegexConfig(string file)
{
	configFile = file;
	setRegexConfig();
}


int RegexConfig::setRegexConfig()
{
	FILE *pp;
	pp = fopen(configFile.c_str(),"r");
	if(NULL == pp)
	{
		cout << configFile << "open failed,check you path" << endl;
		return -1;
	}
	string str_code;
	string str_content;
	char buf[128];
	string str = "";
	int index = 0;
	while(fgets(buf, 128, pp) != NULL)
	{
		index = str.find_first_of("#",0);
		if(index <2 && index >=0)
		{
			continue;
		}
		str = buf;
		str = str.substr(0,str.length() - 1);
		index = str.find_first_of(":", 0);
		if(index > 0)
		{
			str_code = str.substr(0, index);
			str_content = str.substr(index + 1, str.length());
			regexChain.insert(pair<int,string>(std::atoi(str_code.c_str()),str_content));
		}
	}
	fclose(pp);
	return 0;
}


void RegexConfig::print()
{
	cout << "***************************************************" << endl;
	cout << "filter log with these rules:" << endl;
	map<int,string>::iterator iter;
	for(iter = regexChain.begin();iter != regexChain.end();iter++)
	{
		cout << iter->first << "  " << iter->second << endl;
	}
	if(regexChain.size() == 0)
	{
		cout << "warning : no rule  config" << endl;
	}
	cout << "***************************************************" << endl;
}


/*
//util test
int main()
{
	string configFile = "../conf/monitorLog.conf";
	RegexConfig * regexConf = new RegexConfig(configFile);
	regexConf->print();
	return 1;
}
*/
