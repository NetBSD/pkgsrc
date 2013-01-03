#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: jetty.sh,v 1.3 2013/01/03 13:56:14 ryoon Exp $
#
# PROVIDE: jetty
# REQUIRE: DAEMON
#

if [ -r /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="jetty"
rcvar=$name
command="@JETTY_HOME@/bin/jetty.sh"
pidfile="jetty.pid"
jetty_user="@JETTY_USER@"
jetty_group="@JETTY_GROUP@"
start_cmd="$command start"
stop_cmd="$command stop"
restart_cmd="$stop_cmd && $start_cmd"
run_cmd="jetty_run"
version_cmd="jetty_version"
debug_cmd="jetty_debug"
extra_commands="run version debug"
start_precmd="jetty_precmd"

PREFIX=@PREFIX@

JAVA_OPTIONS="-Xmx768M -Djava.nio.channels.spi.SelectorProvider=sun.nio.ch .PollSelectorProvider"

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
	JAVA="@JAVA_HOME@/bin/java"
	export JAVA
fi


JETTY_HOME=@JETTY_HOME@
JETTY_PORT=@JETTY_PORT@
JETTY_RUN=@VARBASE@/run/jetty
JETTY_PID=${pidfile}
export JETTY_HOME
export JETTY_PORT
export JETTY_RUN
export JETTY_PID

CLASSPATH=${CLASSPATH}:${PREFIX}/lib/java/servlet.jar:${PREFIX}/lib/java/jaxp.jar:${PREFIX}/lib/java/parser.jar:${PREFIX}/lib/java/crimson.jar:${PREFIX}/lib/java/ant.jar

if [ -n "${jetty_classpath}" ]
then
	CLASSPATH=${CLASSPATH}:${jetty_classpath}
fi
export CLASSPATH

jetty_precmd()
{
	if [ ! -d @VARBASE@/run/jetty ]; then
		@MKDIR@ ${JETTY_RUN}
		@CHMOD@ 0750 ${JETTY_RUN}
		@CHOWN@ ${jetty_user}:${jetty_group} ${JETTY_RUN}
	fi
}

jetty_start()
{
	cd ${JETTY_HOME}/logs
	@SU@ ${jetty_user} -c "${command} start"
}

jetty_stop()
{
	rc_pid=$(check_pidfile ${JETTY_RUN}/${JETTY_PID} "${JAVA_HOME}/bin/java")
	@SU@ ${jetty_user} -c "${command} stop"
	wait_for_pids $rc_pid
}


jetty_run()
{
	cd ${JETTY_HOME}/logs
	@SU@ ${jetty_user} -c "${command} run"
}

if [ -f /etc/rc.subr ]
then
	load_rc_config "$name"
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${jetty_flags} ${command_args}
fi
