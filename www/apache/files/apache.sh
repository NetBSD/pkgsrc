#!/bin/sh
#
# $NetBSD: apache.sh,v 1.15 2001/12/26 22:03:38 jlam Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# To start apache at startup, copy this script to /etc/rc.d and set
# apache=YES in /etc/rc.conf.

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="apache"
rcvar=$name
command="@PREFIX@/sbin/httpd"
ctl_command="@PREFIX@/sbin/apachectl"

apache_start=start
if [ -f @PKG_SYSCONFDIR@/apache_start.conf ]
then
	# This file can reset apache_start to "startssl"
	. @PKG_SYSCONFDIR@/apache_start.conf
fi

required_files="@PKG_SYSCONFDIR@/httpd.conf"
start_cmd="${ctl_command} ${apache_start}"
stop_cmd="${ctl_command} stop"
restart_cmd="${ctl_command} restart"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	${start_cmd}
fi
