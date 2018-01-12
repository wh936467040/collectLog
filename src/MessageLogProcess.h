/**********************************
 *  
 * class MessageLogProcess 
 * extend from LogProcess.class
 * author:wanghao200911@163.com
 * date: 2018-01-04
 *
 **********************************/
#ifndef __MESSAGE_LOG_PROCESS_H_
#define __MESSAGE_LOG_PROCESS_H_
#include "LogProcess.h"
#include "LogFilter.h"

namespace MONITOR_LOG
{
	class MessageLogProcess:public LogProcess
	{
		public:
			MessageLogProcess(std::string fileName,std::string fileName0,LogFilter * filter);

			int run();   /* cover virtual function */

			/*
			 * function  :  read log and filter important log 
			 * 		send important log to server ;
			 * return    :  file pointer length;
			 * */		
			long readFile(std::string fileName,long readLen); // read log return where read;

		private:
			std::string mFileName;   // log file name 
			std::string mFileName0;  //oldFile name such as messages.0
	};
}
#endif 
