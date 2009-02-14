#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: tomcat.sh,v 1.1.1.1 2009/02/14 12:02:09 adrianp Exp $
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
tomcat_user="@TOMCAT_USER@"
tomcat_group="@TOMCAT_GROUP@"
start_cmd="$command start"
stop_cmd="$command stop"
restart_cmd="$stop_cmd && $start_cmd"
run_cmd="tomcat_run"
version_cmd="tomcat_version"
debug_cmd="tomcat_debug"
extra_commands="run version debug"

PREFIX=@PREFIX@

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
fi

CATALINA_HOME=@TOMCAT_HOME@
TOMCAT_HOME=@TOMCAT_HOME@
export CATALINA_HOME
export TOMCAT_HOME

CLASSPATH=${CLASSPATH}:${PREFIX}/lib/java/servlet.jar:${PREFIX}/lib/java/jaxp.jar:${PREFIX}/lib/java/parser.jar:${PREFIX}/lib/java/crimson.jar:${PREFIX}/lib/java/ant.jar

if [ -n "${tomcat_classpath}" ]
then
	CLASSPATH=${CLASSPATH}:${tomcat_classpath}
fi
export CLASSPATH

tomcat_run()
{
	${command} run
}

tomcat_version()
{
	${command} version
}

tomcat_debug()
{
	${command} debug
}

if [ -f /etc/rc.subr ]
then
	load_rc_config "$name"
	run_rc_command "$1"
else
	echo -n ' ${name}'
	exec ${command} ${tomcat_flags} ${command_args}
fi
