#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dansguardian.sh,v 1.3 2014/03/28 14:13:25 prlw1 Exp $
#
# PROVIDE: dansguardian
# REQUIRE: DAEMON LOGIN
# KEYWORD: shutdown

. /etc/rc.subr

name="dansguardian"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
