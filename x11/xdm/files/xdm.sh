#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xdm.sh,v 1.3 2012/04/29 08:04:56 sbd Exp $
#

# PROVIDE: xdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="xdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/xdm-config"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
