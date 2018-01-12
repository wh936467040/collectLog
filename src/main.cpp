/****************************************
update: filter message and send important log top server;
author: wanghao200911@163.com
date: 2017-12-27
****************************************/
#include "sendinfo.h"
#include "MyUtil.h"
#include "Parameter.h"
#include "MySendFactory.h"
#include "RegexConfig.h"
#include "LogFilter.h"
#include "MessageLogProcess.h"

using namespace std;
using namespace PROJECT_PUBLIC;
using namespace MONITOR_LOG;

int main()
{
	string conf = "../conf/auto_monitor.conf";
	string alarmConf = "../conf/AlarmInfo.conf";
	string regexConf = "../conf/monitorLog.conf";
	string D5000_HOME = MyUtil::getD5000HomePath();
	string logFile = D5000_HOME + "/var/log/messages";
	string logFile0 = D5000_HOME + "/var/log/messages.0";

	Parameter * para = new Parameter(conf,alarmConf);
	RegexConfig * reg = new RegexConfig(regexConf);
	para -> print();
	reg -> print();
	LogFilter * logFilter = new LogFilter (reg -> regexChain);
	MySendFactory mySend = MySendFactory(para);

	LogProcess * msgProcesser = new MessageLogProcess(logFile,logFile0,logFilter);
	msgProcesser -> run();	
	return 1;
}



