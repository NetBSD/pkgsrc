#!/bin/sh

PREFIX=%%PREFIX%%

case "$1" in

start)
	${PREFIX}/bin/xfstt --sync >/dev/null
	${PREFIX}/bin/xfstt --user nobody --notcp --daemon && echo -n ' xfstt'
	;;
stop)
	kill `ps -auxwww | grep xfstt | awk '{ print $2 }'`
	echo -n ' xfstt'
	;;
*)
	echo "$0 start | stop"
	;;

esac
