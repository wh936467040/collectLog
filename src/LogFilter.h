/**************************************************
class LogFilter
author:wanghao200911@163.com
date:2018-01-03
update : add regex chain to filter important message
***************************************************/
#ifndef __LOGFILTER_H_
#define __LOGFILTER_H_
#include <string>
#include <map>


namespace MONITOR_LOG
{
	class LogFilter
	{

		private:
			std::map<int,std::string> regexChain;
		public:
			int process(std::string log);  /* if match regex chain return regex No, else return 0 */
			void print();                  /* print chain; */
			LogFilter(std::map<int,std::string> chain);
	};
}
#endif
