#!/bin/sh
#
# $NetBSD: squid.sh,v 1.4 2000/12/16 09:45:44 hubertf Exp $
#

case $1 in
start)
	if [ `ps -auxwww | grep RunCache | grep -v grep | wc -l'` -ne 0 ]; then
		echo "squid already running."
		exit 1
	fi

	if [ -x @PREFIX@/sbin/RunCache -a -f /etc/squid.conf ];
	then
		@PREFIX@/sbin/RunCache >/dev/null 2>&1 &
		echo -n ' squid'
	fi
	;;
stop)
	if [ `ps -auxwww | grep RunCache | grep -v grep | wc -l'` -ne 0 ]; then
		kill `ps -auxwww | grep RunCache | awk '{print $2}'`
		@PREFIX@/sbin/squid -k shutdown
	else
		echo "squid not running."
	fi
	;;
restart)
	sh $0 stop
	sh $0 start
	;;
*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac
