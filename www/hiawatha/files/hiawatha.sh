#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hiawatha.sh,v 1.3 2024/04/15 14:52:33 hauke Exp $
#
# PROVIDE: hiawatha
# REQUIRE: DAEMON
# KEYWORD: shutdown

name="hiawatha"
command="@PREFIX@/sbin/${name}"

if [ -f @SYSCONFBASE@/rc.subr ]; then
    	. @SYSCONFBASE@/rc.subr

	rcvar=${name}
	required_files="@PKG_SYSCONFDIR@/${name}.conf"
	pidfile="@VARBASE@/run/${name}.pid"

	load_rc_config ${name}
	run_rc_command "$1"
else
        @ECHO@ -n " ${name}"
	${command} ${hiawatha_flags}
fi
