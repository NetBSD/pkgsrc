#! /bin/sh
#
# $NetBSD: tomcat.sh,v 1.3 2001/04/02 18:50:50 jwise Exp $
#
# PROVIDE: tomcat
# REQUIRE: DAEMON

PREFIX=@PREFIX@

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME=${PREFIX}/java
	export JAVA_HOME
fi

CLASSPATH=${CLASSPATH}:${PREFIX}/lib/java/servlet.jar:${PREFIX}/lib/java/jaxp.jar:${PREFIX}/lib/java/parser.jar
export CLASSPATH

name="tomcat"
command="${PREFIX}/tomcat/bin/tomcat.sh"

cmd=${1:-start}

if [ -x ${command} ]
then
	case ${cmd} in
	run|start|stop)
		echo "Starting ${name}."
		(cd ${PREFIX}/tomcat && ${command} ${cmd})
		;;

	restart)
		( $0 stop )
		sleep 5
		$0 start
		;;

	*)
		echo 1>&2 "Usage: $0 [restart|start|stop]"
		exit 1
		;;
	esac
fi
exit 0
