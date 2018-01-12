CC=gcc
CPP=g++ -g
dbg_option=
project=exe2_log_2.0.0_beta
platform_include=$(HOME)/src/include
boost_include=$(HOME)/src/boost

COMMONDEF=-D_POSIX_REALTIME_SIGNALS -D_REENTRANT -DLINUX_AIO_NOTIFY_USING_THREAD -DLINUX_USING_QUEUED_IO
CFLAGS=-fpic $(dbg_option) -I $(platform_include) -I $(boost_include)

platform_lib_path=$(HOME)/lib
platform_lib=-lc -lm -lrt -lpthread -ldl -lsend

boost_path=$(HOME)/src/boost/stage/lib/
boost_lib=$(boost_path)libboost_regex.a

%.o:%.cpp
	$(CPP) -c  $(CFLAGS) $< -o $@
%.o:%.cc
	$(CPP) -c  $(CFLAGS) $< -o $@

source_objects=log.o Parameter.o RegexConfig.o LogFilter.o MyUtil.o MySendFactory.o MessageLogProcess.o main.o

object_files=$(source_objects) 

#final_object=control

#all : $(final_object)

.PHONY : all clean rebuild 
	
$(project): $(object_files)
	$(CPP) -o $@ $(object_files)-L ../lib -L$(platform_lib_path) $(platform_lib) $(boost_lib) 
	cp -rp $(project) ../bin
	@rm -rf $(object_files)	
	@echo make ok.

clean :	
	@rm -rf $(object_files)	
#	@rm -rf $(final_object)

rebuild	: clean	all
