#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cherokee.sh,v 1.1.1.1 2006/05/01 07:22:29 jmmv Exp $
#
# PROVIDE: cherokee
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="cherokee"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="&"
required_files="@PKG_SYSCONFDIR@/cherokee/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${cherokee_flags} ${command_args}
fi
