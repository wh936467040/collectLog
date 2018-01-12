/**************************************************
 * 
 * class LogFilter
 * author:wanghao200911@163.com
 * date:2018-01-03
 * update : add regex chain to filter important message
 *
 **************************************************/
#include "LogFilter.h"
#include "boost/regex.hpp"

#include <exception>
#include <iostream>
using namespace std;
using namespace MONITOR_LOG;

LogFilter::LogFilter(map<int,string> chain)
{
	regexChain = chain;
}

int LogFilter::process(string log)  
{
	map<int,string>::iterator iter;
	for(iter = regexChain.begin();iter != regexChain.end();iter++)
	{
		string strRegex = iter -> second;
		boost::regex oRegex(strRegex);
		boost::smatch oResult;
		try
		{
			if(boost::regex_search(log,oResult,oRegex))
			{
				return iter -> first;
			}
		}
		catch (exception)
		{
			cout << "正则规则配置错误" << endl;
			continue;
		}
	}
	return 0;
}

void LogFilter::print()
{
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
}

