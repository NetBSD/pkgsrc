#!/bin/sh
#
# $NetBSD: thttpd.sh,v 1.8 2002/02/05 06:04:43 jlam Exp $
#
# PROVIDE: thttpd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="thttpd"
rcvar=$name
command=@PREFIX@/sbin/${name}
command_args="-C @PKG_SYSCONFDIR@/${name}.conf"
required_files="@PKG_SYSCONFDIR@/${name}.conf"

if [ -f /etc/rc.subr ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${thttpd_flags} ${command_args}
fi
