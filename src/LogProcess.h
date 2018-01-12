/*****************************************
 *
 * class LogProcess 
 * an abstract class as an interface for log read and log Filter
 * author: wanghao200911@163.com
 * date: 2018-01-04
 * version:1.0.0
 *
 *****************************************/
#ifndef __LOG_FILTER_H_
#define __LOG_FILTER_H_
#include "LogFilter.h"
namespace MONITOR_LOG
{
	class LogProcess 
	{
		public:
			/* *
			 * pure vitual function as an interface 
			 * function: read log and use filter 
			 * */
			virtual int run() = 0; 
		protected:
			LogFilter * mFilter;
	};
}
#endif 
