#!/bin/sh
#
# $NetBSD: thttpd.sh,v 1.1 2000/07/27 12:42:08 jlam Exp $
#

name="thttpd"
pidfile="/var/run/${name}.pid"

command=${1:-start}

case ${command} in
start)
	if [ -x @PREFIX@/sbin/thttpd -a -f /etc/thttpd.conf ]
	then
		echo "Starting ${name}."
		@PREFIX@/sbin/thttpd -i ${pidfile} -C /etc/thttpd.conf
	fi
	;;
stop)
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
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
	if [ -f ${pidfile} ]; then
		pid=`head -1 ${pidfile}`
		echo "${name} is running as pid ${pid}."
	else
		echo "${name} is not running."
	fi
	;;
esac
exit 0
