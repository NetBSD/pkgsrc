#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: wdm.sh,v 1.3 2006/10/18 20:23:15 reed Exp $
#

# PROVIDE: wdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="wdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
command_args="-daemon"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/wdm-config"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
