#!/bin/sh
#
# $NetBSD: thttpd.sh,v 1.7 2001/11/26 07:34:08 jlam Exp $
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
command_args="-C @PKG_SYSCONFDIR@/${name}.conf"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -e /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${thttpd_flags} ${command_args}
fi
