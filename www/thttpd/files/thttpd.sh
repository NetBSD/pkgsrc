#!/bin/sh
#
# $NetBSD: thttpd.sh,v 1.5 2001/11/19 16:23:17 jlam Exp $
#
# PROVIDE: thttpd
# REQUIRE: DAEMON

if [ -d /etc/rc.d -a -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="thttpd"
rcvar=$name
command=@PREFIX@/sbin/${name}
command_args="-C @CONFDIR@/${name}.conf"
required_files="@CONFDIR@/${name}.conf"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n " ${name}"
	exec ${command} ${thttpd_flags} ${command_args}
fi

load_rc_config $name
run_rc_command "$1"
