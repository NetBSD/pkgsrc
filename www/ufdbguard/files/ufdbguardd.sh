#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: ufdbguardd.sh,v 1.1 2022/02/18 11:57:30 sborrill Exp $
#

# PROVIDE: ufdbguardd
# REQUIRE: daemon

$_rc_subr_loaded . /etc/rc.subr

name="ufdbguardd"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/ufdbguard/${name}.pid"
required_files="@PKG_SYSCONFDIR@/ufdbGuard.conf"

load_rc_config $name
run_rc_command "$1"
