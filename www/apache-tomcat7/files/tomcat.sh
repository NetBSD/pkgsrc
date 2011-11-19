#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: tomcat.sh,v 1.1.1.1 2011/11/19 17:11:11 ryoon Exp $
#
# PROVIDE: tomcat
# REQUIRE: DAEMON
#

if [ -r /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="tomcat"
rcvar=$name
command="@TOMCAT_HOME@/bin/catalina.sh"
pidfile="@VARBASE@/run/tomcat/catalina.pid"
tomcat_user="@TOMCAT_USER@"
tomcat_group="@TOMCAT_GROUP@"
start_cmd="$command start"
stop_cmd="$command stop"
restart_cmd="$stop_cmd && $start_cmd"
run_cmd="tomcat_run"
version_cmd="tomcat_version"
debug_cmd="tomcat_debug"
extra_commands="run version debug"
start_precmd="tomcat_precmd"

PREFIX=@PREFIX@

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
fi

CATALINA_HOME=@TOMCAT_HOME@
TOMCAT_HOME=@TOMCAT_HOME@
CATALINA_PID=${pidfile}
export CATALINA_HOME
export TOMCAT_HOME
export CATALINA_PID

CLASSPATH=${CLASSPATH}:${PREFIX}/lib/java/servlet.jar:${PREFIX}/lib/java/jaxp.jar:${PREFIX}/lib/java/parser.jar:${PREFIX}/lib/java/crimson.jar:${PREFIX}/lib/java/ant.jar

if [ -n "${tomcat_classpath}" ]
then
	CLASSPATH=${CLASSPATH}:${tomcat_classpath}
fi
export CLASSPATH

tomcat_precmd()
{
	if [ ! -d @VARBASE@/run/tomcat ]; then
		@MKDIR@ @VARBASE@/run/tomcat
		@CHMOD@ 0750 @VARBASE@/run/tomcat
		@CHOWN@ ${tomcat_user}:${tomcat_group} @VARBASE@/run/tomcat
	fi
}

tomcat_start()
{
	cd $CATALINA_HOME/logs
	@SU@ ${tomcat_user} -c "${command} start"
}

tomcat_stop()
{
	rc_pid=$(check_pidfile $pidfile "${JAVA_HOME}/bin/java")
	@SU@ ${tomcat_user} -c "${command} stop"
	wait_for_pids $rc_pid
}


tomcat_run()
{
	cd ${CATALINA_HOME}/logs
	@SU@ ${tomcat_user} -c "${command} run"
}

tomcat_version()
{
	@SU@ ${tomcat_user} -c "${command} version"
}

tomcat_debug()
{
	cd ${CATALINA_HOME}/logs
	@SU@ ${tomcat_user} -c "${command} debug"
}

if [ -f /etc/rc.subr ]
then
	load_rc_config "$name"
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${tomcat_flags} ${command_args}
fi
