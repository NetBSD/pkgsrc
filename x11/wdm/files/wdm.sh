#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: wdm.sh,v 1.1 2003/02/23 17:33:31 salo Exp $
#

# PROVIDE: wdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="wdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/lib/X11/wdm/wdm-config"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
