#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: apache.sh,v 1.26 2005/02/28 23:30:49 abs Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# You will need to set some variables in /etc/rc.conf to start Apache:
#
# apache=YES 
# apache_start="start"  # set to "startssl" to allow HTTPS connections
#			# if ap-ssl is installed; this variable is optional

if [ -f /etc/rc.subr ]
then
	. /etc/rc.subr
fi

name="apache"
rcvar=$name
command="@PREFIX@/sbin/httpd"
ctl_command="@PREFIX@/sbin/apachectl"
required_files="@PKG_SYSCONFDIR@/httpd.conf"
extra_commands="reload"
start_cmd="apache_doit start"
stop_cmd="apache_doit stop"
restart_cmd="apache_doit restart"
reload_cmd="apache_doit reload"

apache_doit ()
{
	: ${apache_start:=start}

	case $1 in
	start)	action=${apache_start} ;;
	restart)action=re${apache_start} ;;	# For apache_start=startssl
	reload)	action=graceful ;;
	*)	action=$1 ;;
	esac
	${ctl_command} ${action}
}

if [ -f /etc/rc.subr -a -f /etc/rc.conf -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]
then
	load_rc_config $name
	run_rc_command "$1"
else
	apache_doit "$1"
fi
