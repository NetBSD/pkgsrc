#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lighttpd.sh,v 1.4 2024/01/21 09:33:35 triaxx Exp $
#
# PROVIDE: lighttpd
# KEYWORD: chrootdir
# REQUIRE: DAEMON
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start lighttpd:
#
# lighttpd=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

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
