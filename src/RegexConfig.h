/****************************
file: RegexConfig.cpp
author: wanghao200911@163.com
date: 2018-01-03
version:1.0
****************************/
#ifndef __REGEXCONFIG_H_
#define __REGEXCONFIG_H_
#include <string>
#include <map>
using namespace std;
namespace MONITOR_LOG
{
	class RegexConfig
	{
		public:
			static map<int,string> regexChain;  //正则表达式链
			static int setRegexConfig();        //读取正则表达式链
			static void print();                 //打印正则表达式链	
			RegexConfig(string file);    //输入配置文件名构造
		private:
			static string configFile;
	};
}

#endif
