#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: xdm.sh,v 1.2 2007/08/06 16:43:40 tron Exp $
#

# PROVIDE: xdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="xdm"
rcvar=$name
xdm_config="/etc/X11/${name}/${name}-config"
command="@PREFIX@/bin/${name}"
command_args="-config ${xdm_config}"
pidfile="/var/run/${name}.pid"
required_files="${xdm_config}"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
