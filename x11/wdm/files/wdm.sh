#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: wdm.sh,v 1.2 2003/05/07 18:27:07 jmmv Exp $
#

# PROVIDE: wdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="wdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/wdm-config"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
