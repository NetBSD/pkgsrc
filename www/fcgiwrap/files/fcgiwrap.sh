#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fcgiwrap.sh,v 1.1 2024/10/01 03:21:03 ryoon Exp $
#
# PROVIDE: fcgiwrap
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start fcgiwrap:
#
# fcgiwrap=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="fcgiwrap"
rcvar=${name}
command="@PREFIX@/sbin/${name}"
pidfile="@VARBASE@/run/${name}/${name}.pid"
fcgiwrap_user="@FCGIWRAP_USER@"
fcgiwrap_group="@FCGIWRAP_GROUP@"
start_precmd="fcgiwrap_precmd"
start_cmd="fcgiwrap_start"
start_postcmd="fcgiwrap_poststart"
fcgiwrap_socket="@VARBASE@/run/${name}/${name}.sock"

fcgiwrap_precmd()
{
	if [ ! -d @VARBASE@/run/${name} ]; then
		@MKDIR@ @VARBASE@/run/${name}
		@CHOWN@ ${fcgiwrap_user}:${fcgiwrap_group} @VARBASE@/run/${name}
	fi

	if [ -e ${fcgiwrap_socket} ]; then
		@RM@ -f ${fcgiwrap_socket}
	fi
}

fcgiwrap_start()
{
	@SU@ -m ${fcgiwrap_user} -c "${command} -s unix:${fcgiwrap_socket}" &
}

fcgiwrap_poststart() {
	echo $! > ${pidfile}
}

fcgiwrap_stop()
{
	kill -HUP $(check_pidfile $pidfile $name)
}

load_rc_config $name
run_rc_command "$1"
