#!/bin/sh
#
# $NetBSD: apache.sh,v 1.4 2002/07/07 00:45:19 tv Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# To start apache at startup, copy this script to /etc/rc.d and set
# apache=YES in /etc/rc.conf.

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="apache"
rcvar=$name
command="@PREFIX@/sbin/httpd"
ctl_command="@PREFIX@/sbin/apachectl"
required_files="@PKG_SYSCONFDIR@/httpd.conf"
extra_commands="reload"
start_cmd="apache_doit start"
stop_cmd="apache_doit stop"
restart_cmd="apache_doit restart"
reload_cmd="apache_doit reload"

# "${apache_start}" is the subcommand sent to apachectl to control how
# httpd is started.  It's value may be overridden in:
#
#	@PKG_SYSCONFDIR@/apache_start.conf
#	/etc/rc.conf
#	/etc/rc.conf.d/apache,
#
# in order of increasing precedence.  Its possible values are "start"
# and "startssl", and defaults to "start".
#
apache_start=start
if [ -f @PKG_SYSCONFDIR@/apache_start.conf ]
then
	. @PKG_SYSCONFDIR@/apache_start.conf
fi

apache_doit ()
{
	case $1 in
	start)	action=${apache_start} ;;
	reload)	action=graceful ;;
	*)	action=$1 ;;
	esac
	${ctl_command} ${action}
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	apache_doit "$1"
fi
