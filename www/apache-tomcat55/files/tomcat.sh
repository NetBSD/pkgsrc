#! @RCD_SCRIPTS_SHELL@
#
# $NetBSD: tomcat.sh,v 1.1.1.1 2006/01/03 18:12:37 abs Exp $
#
# PROVIDE: tomcat
# REQUIRE: DAEMON
#
# To start tomcat at startup, copy this script to /etc/rc.d and set
# tomcat=YES in /etc/rc.conf.

PREFIX=@PREFIX@
TOMCAT_LIB=@TOMCAT_LIB@

if [ -z "${JAVA_HOME}" ]
then
	JAVA_HOME="@JAVA_HOME@"
	export JAVA_HOME
fi

name="tomcat"
rcvar=$name
command="${TOMCAT_LIB}/bin/catalina.sh"

# set defaults
if [ -r /etc/rc.conf ]
then
	. /etc/rc.conf
else
	eval ${rcvar}=YES
fi

# $flags from environment overrides ${rcvar}_flags
if [ -n "${flags}" ]
then
	eval ${rcvar}_flags="${flags}"
fi

CLASSPATH=${CLASSPATH}:${PREFIX}/lib/java/servlet.jar:${PREFIX}/lib/java/jaxp.jar:${PREFIX}/lib/java/parser.jar:${PREFIX}/lib/java/crimson.jar:${PREFIX}/lib/java/ant.jar
if [ -n "${tomcat_classpath}" ]
then
	CLASSPATH=${CLASSPATH}:${tomcat_classpath}
fi
export CLASSPATH

cmd=${1:-start}

checkyesno()
{
	eval _value=\$${1}
	case $_value in
	[Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)	return 0 ;;
	[Nn][Oo]|[Ff][Aa][Ll][Ss][Ee]|[Oo][Ff][Ff]|0)	return 1 ;;
	*)
		echo "\$${1} is not set properly."
		return 1
		;;
	esac
}

if checkyesno ${rcvar}
then
	if [ -x ${command} ]
	then
		case ${cmd} in
		run|start)
			echo "Starting ${name}."
			(cd ${TOMCAT_LIB} && ${command} ${cmd})
			;;

		stop)
			echo "Stopping ${name}."
			(cd ${TOMCAT_LIB} && ${command} ${cmd})
			;;

		restart)
			( $0 stop )
			sleep 5
			$0 start
			;;

		flush)
			cd ${TOMCAT_LIB}/work && rm -rf */*
			;;

		*)
			echo 1>&2 "Usage: $0 [restart|start|stop|flush]"
			exit 1
			;;
		esac
	fi
fi
exit 0
