#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zss3.sh,v 1.3 2006/05/06 22:38:28 wiz Exp $
#
# PROVIDE: zss3
# REQUIRE: DAEMON
# BEFORE: zope3
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="zss3"
rcvar=$name
extra_commands="status"
command="@PREFIX@/share/zope3/bin/zdctl.py"
start_cmd="zss3_start"
start_precmd="zss3_precmd"
stop_cmd="zss3_stop"
stop_precmd="zss3_precmd"
restart_cmd="zss3_restart"
restart_precmd="zss3_precmd"
status_cmd="zss3_status"
status_precmd="zss3_precmd"
zss3_instance_home="@VARBASE@/zss3"
required_dirs="${zss3_instance_home}"
command_args="--daemon --socket-name ${zss3_instance_home}/var/zdsock --program ${zss3_instance_home}/bin/runzeo"

zss3_precmd() {
    for _dir in $required_dirs; do
    if test ! -d "${_dir}"; then
        err 1 "${_dir} is not a directory."
    fi
    done
    if test -z "${zss3_user}"; then
        zss3_user="@ZOPE3_USER@"
    fi
    command_args="${command_args} --user ${zss3_user}"
}

zss3_start() {
    echo -n "Starting Zope Storage Server: "
    ${command} ${rc_flags} ${command_args} start
}

zss3_stop() {
    echo -n "Stopping Zope Storage Server: "
    ${command} ${rc_flags} ${command_args} stop
}

zss3_restart() {
    echo -n "Restarting Zope Storage Server: "
    ${command} ${rc_flags} ${command_args} restart
}

zss3_status() {
    ${command} ${rc_flags} ${command_args} status
}

load_rc_config $name
run_rc_command "$1"
