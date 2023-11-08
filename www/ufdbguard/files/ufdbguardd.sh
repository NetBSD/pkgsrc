#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ufdbguardd.sh,v 1.3 2023/11/08 15:05:18 sborrill Exp $
#

# PROVIDE: ufdbguardd
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="ufdbguardd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/ufdbguard/${name}.pid"
required_files="@PKG_SYSCONFDIR@/ufdbGuard.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
