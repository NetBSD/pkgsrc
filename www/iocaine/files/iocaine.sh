#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: iocaine.sh,v 1.1 2026/08/30 14:31:38 leot Exp $
#
# PROVIDE: iocaine
# REQUIRE: NETWORKING DAEMON
# KEYWORD: shutdown

name="iocaine"
command="@PREFIX@/sbin/daemonize"
pidfile="@VARBASE@/run/${name}/${name}.pid"

task="@PREFIX@/bin/${name}"
procname="${task}"

command_args="-p ${pidfile} \
	-u @IOCAINE_USER@ \
	-c @IOCAINE_DATADIR@ \
	-e @IOCAINE_LOGDIR@/stderr \
	-o @IOCAINE_LOGDIR@/stdout \
	${task} --config-path @PKG_SYSCONFDIR@/conf.d start"

iocaine_precmd()
{
	if [ ! -e "@VARBASE@/run/${name}" ]; then
		install -d -o @IOCAINE_USER@ -g @IOCAINE_GROUP@ \
			@VARBASE@/run/${name};
	fi
}

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr
start_precmd="iocaine_precmd"

load_rc_config ${name}
run_rc_command "$1"
