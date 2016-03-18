#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lighttpd.sh,v 1.2 2016/03/18 11:37:22 bsiegert Exp $
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
command_args="-f ${conf_file}"

load_rc_config $name
run_rc_command $1
