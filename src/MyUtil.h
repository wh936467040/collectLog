/*****************************************
 *
 * class   :     MyUtil.class
 * author  :     wanghao200911@163.com
 * update  :     2018-01-08, add replaceAll(str0,str1), where std::string not exist;
 * warning :     when update this class ,don't use namespace std;
 * 	         because ftos may conflict with namespace std::cstdlib;
 *
 *****************************************/
#ifndef __MYUTIL_H__
#define __MYUTIL_H__

#include <string>

namespace PROJECT_PUBLIC
{
	class MyUtil
	{
		public:
			/* input file full name and return  file size byte); */
			static long getFileSize(std::string file); 

			/* get D5000_HOME path ,if not exist return "null";  */
			static std::string getD5000HomePath();     

			/* input a float or double and return %.2d format ;  */
			static double math_dot2(double x);     

			/* transformat int to string                         */
			static std::string itos(int i);

			/* transformat long to string                        */
			static std::string ltos(long l);	

			/* transformat float to string                       */
			static std::string ftos(float f);

			/* transformat float to string with .2%f format;     */
			static std::string f2tos(float f);

			/* *
			 *
			 * find all oldValue from str and replace with newValue ;
			 * and replaceAll was not found in std::string;
			 *
			 * */
			static std::string replaceAll(std::string str,std::string oldValue,std::string newValue);

			/* *
			 *
			 * fuction: get time :30 or ;00. and sleep 30 
			 * author wxs 
			 * return time in pointer str 
			 * use string getTime(int stime) will be better 
			 * */
			static int getTime(char* str, int stime); 

			/* *
			 * same as getTime(char* str ,int stime)
			 * author wxs
			 * and return a string 
			 * */
			static std::string getTime(int stime);
			/* *
			 * same as unistd::sleep,if use this function ,we can compile any unix os 
			 * but if use sleep ,old g++ version need to include <unistd.h> .
			 * and new version don't need to include.
			 * */
			static int Sleep(int stime); 

	};
}
#endif
