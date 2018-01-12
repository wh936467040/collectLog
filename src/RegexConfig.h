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
			static map<int,string> regexChain;  //������ʽ��
			static int setRegexConfig();        //��ȡ������ʽ��
			static void print();                 //��ӡ������ʽ��	
			RegexConfig(string file);    //���������ļ�������
		private:
			static string configFile;
	};
}

#endif
