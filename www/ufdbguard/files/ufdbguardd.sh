#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ufdbguardd.sh,v 1.2 2022/04/04 13:21:41 sborrill Exp $
#

# PROVIDE: ufdbguardd
# REQUIRE: DAEMON

$_rc_subr_loaded . /etc/rc.subr

name="ufdbguardd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/ufdbguard/${name}.pid"
required_files="@PKG_SYSCONFDIR@/ufdbGuard.conf"

load_rc_config $name
run_rc_command "$1"
