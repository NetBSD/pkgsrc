#!/bin/sh
#
# $NetBSD: fcgi_daemon.sh,v 1.1 2026/11/04 13:46:52 ast Exp $
#

# PROVIDE: fcgi_daemon
# REQUIRE: DAEMON
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="fcgi_daemon"
pidfile="/var/run/${name}.pid"
sockfile="/var/run/${name}.sock"
rcvar=$name

start_cmd="fcgi_daemon_start"
status_cmd="fcgi_daemon_status"
stop_cmd="fcgi_daemon_stop"

extra_commands="status"

fcgi_daemon_args="-p ${pidfile} -s ${sockfile} -u nginx -g nginx -w 2 -d"

cmd_args=${fcgi_daemon_flags:-$fcgi_daemon_args}

perl='/usr/pkg/bin/perl'
[ -x ${perl} ] || { echo "Missing ${perl}">&2; exit 1; }

cmd=`${perl} -MFCGI::Daemon -e 'print $INC{"FCGI/Daemon.pm"}' 2>/dev/null`
[ -f "${cmd}" ] || { echo "Missing FCGI::Daemon Perl module">&2; exit 1; }

fcgi_daemon_start()
{
    /usr/bin/env - ${perl} ${cmd} ${cmd_args}
    if [ $? -eq 0 ]; then
        echo "$name manager and workers started."
    else
        echo "$name failed to start."
    fi
}

fcgi_daemon_status()
{
    local pids p t

    pids=`/usr/bin/pgrep FCGI::Daemon`
    [ -z "$pids" ] && { echo "No $name running."; exit 1; }

    # list all FCGI::Daemon processes
    t=/bin/cat
    for p in $pids; do
        /bin/ps -ouser,group,pid,ppid,cpu,vsz,rss,wchan,time,command -p $p | $t
        t='/usr/bin/tail -1'
    done

    # list all socket files
    /usr/bin/sockstat -l | /usr/bin/head -1
    /usr/bin/sockstat -l | /usr/bin/grep ${sockfile}

    return 0
}

fcgi_daemon_stop()
{
    kill `cat ${pidfile} 2>/dev/null` >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "$name stopped."
    else
        echo "Failed to stop $name."
        fcgi_daemon_status
    fi
}

load_rc_config $name
run_rc_command "$1"
