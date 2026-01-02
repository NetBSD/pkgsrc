#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: sddm.sh,v 1.2 2026/01/02 22:22:23 gutteridge Exp $
#
# PROVIDE: sddm
# REQUIRE: DAEMON LOGIN wscons dbus
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="sddm"
rcvar=$name
procname="@PREFIX@/bin/$name"
pidfile="@VARBASE@/run/$name.pid"
command="@PREFIX@/sbin/daemonize"
command_args="$command_args -p $pidfile"
command_args="$command_args $procname"
start_precmd=sddm_prestart
start_cmd=sddm_start

sddm_prestart() {
	dir="@VARBASE@/lib/$name"
	if @TEST@ ! -d $dir; then
		@MKDIR@ $dir
		@CHMOD@ 0755 $dir
		@CHOWN@ @SDDM_USER@:@SDDM_GROUP@ $dir
	fi
}

sddm_start()
{
	@ECHO@ "Starting ${name}."

	(
		# Delay starting sddm until init has already spawned getty.
		for i in $(seq 1 60); do
			pgrep -f '^/usr/libexec/getty ' >/dev/null && break
			sleep 1
		done
		$command $command_args
	) &
}

load_rc_config $name
run_rc_command "$1"
