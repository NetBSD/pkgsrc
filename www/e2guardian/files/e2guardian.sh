#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: e2guardian.sh,v 1.1 2017/03/03 14:09:18 prlw1 Exp $
#
# PROVIDE: e2guardian
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="e2guardian"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
