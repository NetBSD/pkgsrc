#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lighttpd.sh,v 1.3 2019/11/13 11:53:29 nros Exp $
#
# PROVIDE: lighttpd
# KEYWORD: chrootdir
# REQUIRE: DAEMON

. /etc/rc.subr

name="lighttpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
conf_file="@PKG_SYSCONFDIR@/${name}.conf"
required_files="${conf_file}"
extra_commands="reload"
sig_reload="USR1"
command_args="-f ${conf_file}"

load_rc_config $name
run_rc_command $1
