#!/bin/sh
#
# $NetBSD: thttpd.sh,v 1.6 2001/11/21 21:38:55 jlam Exp $
#
# PROVIDE: thttpd
# REQUIRE: DAEMON

if [ -e /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="thttpd"
rcvar=$name
command=@PREFIX@/sbin/${name}
command_args="-C @CONFDIR@/${name}.conf"
required_files="@CONFDIR@/${name}.conf"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${thttpd_flags} ${command_args}
fi
