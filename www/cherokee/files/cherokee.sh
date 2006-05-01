#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: cherokee.sh,v 1.2 2006/05/01 10:32:51 jmmv Exp $
#
# PROVIDE: cherokee
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="cherokee"
rcvar=$name
command="@PREFIX@/sbin/${name}"
command_args="-b"
required_files="@PKG_SYSCONFDIR@/cherokee/${name}.conf"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	@ECHO@ -n " ${name}"
	${command} ${cherokee_flags} ${command_args}
fi
