#!/bin/sh
#
# $NetBSD: thttpd.sh,v 1.4 2001/01/14 06:14:13 jlam Exp $
#
# PROVIDE: thttpd
# REQUIRE: DAEMON

name="thttpd"
command=@PREFIX@/sbin/${name}

pid=`ps -ax | awk '{print $1,$5}' | grep ${name} | awk '{print $1}'`

cmd=${1:-start}

case ${cmd} in
start)
	if [ "$pid" = "" -a -x ${command} -a -f /etc/${name}.conf ]
	then
		echo "Starting ${name}."
		${command} -C /etc/${name}.conf
	fi
	;;

stop)
	if [ "$pid" != "" ]
	then
		echo "Stopping ${name}."
		kill -TERM ${pid}
	else
		echo "${name} not running?"
	fi
	;;

restart)
	( $0 stop )
	sleep 1
	$0 start
	;;

status)
	if [ "$pid" != "" ]
	then
		echo "${name} is running as pid ${pid}."
	else
		echo "${name} is not running."
	fi
	;;

*)
	echo 1>&2 "Usage: ${name} [restart|start|stop|status]"
	exit 1
	;;
esac
exit 0
