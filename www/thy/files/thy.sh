#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: thy.sh,v 1.1.1.1 2004/04/01 05:19:03 xtraeme Exp $
#
# PROVIDE: thy
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

if [ -f @PKG_SYSCONFDIR@/thyrc ]; then
	. @PKG_SYSCONFDIR@/thyrc
fi

name="thy"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
command_args=${THY_OPTIONS}
pidfile=${THY_PIDFILE:-/var/run/thy.pid}
stop_postcmd="rm -f ${pidfile}"

if [ -f /etc/rc.subr ]; then
	load_rc_config ${name}
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	eval ${command} ${command_args}
fi
