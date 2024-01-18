#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: dtlogin.sh,v 1.2 2024/01/18 20:57:03 vins Exp $
#
# PROVIDE: dtlogin
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown
#

. /etc/rc.subr

name="dtlogin"
rcvar=$name
command="@PREFIX@/dt/bin/${name}"
command_args="-daemon"
pidfile="@VARBASE@/dt/Xpid"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
