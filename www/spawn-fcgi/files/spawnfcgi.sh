#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: spawnfcgi.sh,v 1.1.1.1 2010/02/08 14:37:54 joerg Exp $
#
# PROVIDE: spawnfcgi
# BEFORE: apache cherokee lighttpd nginx
# REQUIRE: DAEMON

. /etc/rc.subr

name="spawnfcgi"
rcvar=$name
command="@PREFIX@/bin/spawn-fcgi"
start_cmd="spawnfcgi_start"
stop_cmd="spawnfcgi_stop"
status_cmd="spawnfcgi_status"
pidfile_base="@VARBASE@/run/spawnfcgi-"

spawnfcgi_pid()
{
	pidfile=${pidfile_base}$1
	job_command=$(eval echo \$${name}_${job}_command)
	rc_pid=`check_pidfile "$pidfile" $job_command`
}

spawnfcgi_start()
{
	rv=0
	for job in "" $spawnfcgi_jobs; do
		[ -z $job ] && continue
		spawnfcgi_pid $job
		if [ -n "${rc_pid}" ]; then
			echo "${name}/$job already running (pid=${rc_pid})."
			rv=1
			continue
		fi
		job_command=$(eval echo \$${name}_${job}_command)
		job_args=$(eval echo \$${name}_${job}_args)
		job_user=$(eval echo \$${name}_${job}_user)
		job_cwd=$(eval echo \$${name}_${job}_cwd)
		job_socket=$(eval echo \$${name}_${job}_socket)
		job_socket_mode=$(eval echo \$${name}_${job}_socket_mode)
		job_address=$(eval echo \$${name}_${job}_address)
		job_children=$(eval echo \$${name}_${job}_children)
		job_php_children=$(eval echo \$${name}_${job}_php_children)

		if [ -n "${job_php_children}" ]; then
			opt_C="-C"
		else
			opt_C=""
		fi
		if [ -n "${job_children}" ]; then
			opt_F="-F"
		else
			opt_F=""
		fi
		if [ -n "${job_socket_mode}" ]; then
			opt_m="-m"
		else
			opt_m=""
		fi
		if [ -n "${job_socket}" ]; then
			opt_s="-s"
		else
			opt_s=""
		fi
		if [ -n "${job_address}" ]; then
			opt_a="-a"
		else
			opt_a=""
		fi
		if [ -n "${job_port}" ]; then
			opt_p="-p"
		else
			opt_p=""
		fi
		echo "Starting ${name}/$job."
		$command -f ${job_command} \
		    -u ${job_user} \
		    -d ${job_cwd:-/} \
		    $opt_C ${job_php_children} \
		    $opt_F ${job_children} \
		    $opt_s ${job_socket} \
		    $opt_m ${job_socket_mode} \
		    $opt_a ${job_address} \
		    $opt_p ${job_port} \
		    -P ${pidfile_base}${job} -- \
		    ${job_command} ${job_args}
	done
	return $rv
}

spawnfcgi_stop()
{
	rv=0
	for job in "" $spawnfcgi_jobs; do
		[ -z $job ] && continue
		spawnfcgi_pid $job
		if [ -n "${rc_pid}" ]; then
			echo "Stopping ${name}/$job."
			kill -TERM ${rc_pid}
			wait_for_pids ${rc_pid}
		else
			echo "${name}/$job is not running."
			rv=1
		fi
	done
	return $rv
}

spawnfcgi_status()
{
	rv=0
	for job in "" $spawnfcgi_jobs; do
		[ -z $job ] && continue
		spawnfcgi_pid $job
		if [ -n "${rc_pid}" ]; then
			echo "${name}/${job} is running as pid ${rc_pid}."
		else
			echo "${name}/${job} is not running."
			rv=1
		fi
	done
	return $rv
}

load_rc_config $name
run_rc_command $1
