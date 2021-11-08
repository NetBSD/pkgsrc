#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: nginx.sh,v 1.4 2021/11/08 01:02:01 khorben Exp $
#
# PROVIDE: nginx
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start nginx:
#
# nginx=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="nginx"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
required_files="@PKG_SYSCONFDIR@/${name}.conf"
pidfile="@VARBASE@/run/${name}.pid"
start_precmd="ulimit -n 2048"
extra_commands="configtest reload"
configtest_cmd="nginx_configtest"

nginx_configtest()
{
	if [ ! -f ${required_files} ]; then
		warn "${required_files} does not exist."
		return 1;
	fi
	${command} -t -c ${required_files}
}

load_rc_config $name
run_rc_command "$1"
