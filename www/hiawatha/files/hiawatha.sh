#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: hiawatha.sh,v 1.2 2003/08/04 11:00:32 jmmv Exp $
#
# PROVIDE: hiawatha
# REQUIRE: DAEMON

PREFIX=@PREFIX@
PKG_SYSCONFDIR=@PKG_SYSCONFDIR@

pidfile=/var/run/hiawatha.pid

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME=${PREFIX}/java
	export ${JAVA_HOME}
fi

CLASSPATH=${PREFIX}/lib/java/hiawatha/hiawatha.jar:${PREFIX}/lib/java/hiawatha/xsls.jar:${PREFIX}/lib/java/saxon.jar:${CLASSPATH}
export CLASSPATH

name="hiawatha"
command="${JAVA_HOME}/bin/java com.pault.hiawatha.Server ${PKG_SYSCONFDIR}/hiawatha.cfg"

if [ ! -d /var/spool/hiawatha ]
then
	echo "you must create /var/spool/hiawatha and any needed spool directories therein before starting hiawatha"
	exit 0
fi

cmd=${1:-start}

case ${cmd} in
	start)
		echo "Starting ${name}."
		cd /var/spool/hiawatha 
		${command}&
		echo $! > ${pidfile}
		;;

	stop)
		echo "Stopping ${name}."
		kill `cat ${pidfile}`
		rm ${pidfile}
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
exit 0
