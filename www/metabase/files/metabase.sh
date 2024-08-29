#!/bin/sh
#
# $NetBSD: metabase.sh,v 1.1 2024/08/29 15:00:26 ryoon Exp $
#
# PROVIDE: metabase
# REQUIRE: DAEMON

. /etc/rc.subr
 
name="metabase"
rcvar=$name
pidfile="@VARBASE@/run/${name}.pid"
start_cmd="metabase_start"
stop_cmd="metabase_stop"
status_cmd="metabase_status"
extra_commands="status"

JAVA_OPTS="${JAVA_OPTS} -XX:+IgnoreUnrecognizedVMOptions"
JAVA_OPTS="${JAVA_OPTS} -Dfile.encoding=UTF-8"
JAVA_OPTS="${JAVA_OPTS} -Dlog4j.configurationFile=file:/usr/pkg/share/metabase/conf/log4j2.xml"
JAVA_OPTS="${JAVA_OPTS} -XX:+CrashOnOutOfMemoryError"
JAVA_OPTS="${JAVA_OPTS} -server"

#export MB_DB_TYPE=postgres
#export MB_DB_DBNAME=metabase
#export MB_DB_PORT=5432
#export MB_DB_USER=metabase_user
#export MB_DB_PASS=metabase_password
#export MB_DB_HOST=localhost
#export MB_EMOJI_IN_LOGS=false

metabase_start()
{
	eval "export -- \$${name}_env"
	cd @METABASE_HOME@/conf
	@SU@ @METABASE_USER@ -c \
		"@JAVA_HOME@/bin/java ${JAVA_OPTS} \
		-jar @METABASE_HOME@/metabase.jar" &
	echo $! > ${pidfile}
}

metabase_stop()
{
	kill ${sig_stop} `cat ${pidfile}`
	rm ${pidfile}
}

metabase_status()
{
	if test -f ${pidfile}; then
		echo "${name} is running as pid `cat ${pidfile}`."
	else
		echo "${name} is not running."
	fi

}

load_rc_config $name
run_rc_command "$1"
