exe2_log_2.0.0
===============

Introduction
---------------

collect log writen by syslog protocol and send to server;
the defalut path is $(HOME)/var/log/messages


Install
---------------
add update sql.conf,create table daily into server machine  ,the settings exist
in ../conf

if libsend.so could be found , run "./exe2_log_2.0.0" could start the software


Build
---------------
the program has used boost/regex, boost_1.6.6 must be install first before make,
if boost library install in $(HOME)/src/boost ,makefile don't need to update, 
and use static boost library is better than dynamic library.


