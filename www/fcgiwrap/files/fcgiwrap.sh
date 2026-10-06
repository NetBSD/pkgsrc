#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: fcgiwrap.sh,v 1.4 2026/10/06 03:15:00 riastradh Exp $
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
fcgiwrap_nchildren=1

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
	echo "Starting ${name}."

        # XXX This should really either:
        #
        # (a) properly daemonize and log to syslog, or
        # (b) run under a process supervisor.
        #
        # But fcgiwrap doesn't do (a), and rc.d doesn't have (b).
        #
        # As a partial measure, we redirect stdin from /dev/null so it
        # doesn't try to read from the tty of whoever runs `service
        # fcgiwrap start'.  But if it prints error output during the
        # startup, we really want the operator to see that unless
        # they've already closed the terminal.  So don't redirect
        # stdout or stderr to /dev/null.
        #
	@SU@ -m ${fcgiwrap_user} -c "${command} ${fcgiwrap_flags} -c ${fcgiwrap_nchildren} -f -s unix:${fcgiwrap_socket} </dev/null" &
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
