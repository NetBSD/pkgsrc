#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: thttpd.sh,v 1.9 2002/09/20 02:02:02 grant Exp $
#
# PROVIDE: thttpd
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="thttpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
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
