REATE TABLE "NET_FLOW_20180111" AT "FUJIAN_MONITOR"
(
	"PROCNAME" VARCHAR(50),
	"PORT" VARCHAR(50),
	"REMIPADDRESS" VARCHAR(50),
	"REMPORT" VARCHAR(50),
	"SEND_DATA" VARCHAR(50),
	"RECIVE_DATA" VARCHAR(50),
	"TIME" VARCHAR(50)) STORAGE( INITIAL 1 , NEXT 1 , MINEXTENTS 1 , on "PRIMARY", FILLFACTOR 0
) ;
