#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: zope3.sh,v 1.1.1.1 2005/10/24 02:25:29 minskim Exp $
#
# PROVIDE: zope3
# REQUIRE: DAEMON
# KEYWORD: shutdown

$_rc_subr_loaded .  /etc/rc.subr

name="zope3"
rcvar=$name
extra_commands="status"
command="@PREFIX@/share/zope3/bin/zdctl.py"
start_cmd="zope3_start"
start_precmd="zope3_precmd"
stop_cmd="zope3_stop"
stop_precmd="zope3_precmd"
restart_cmd="zope3_restart"
restart_precmd="zope3_precmd"
status_cmd="zope3_status"
status_precmd="zope3_precmd"
zope3_instance_home="@VARBASE@/zope3"
required_dirs="${zope3_instance_home}"
command_args="--daemon --socket-name ${zope3_instance_home}/var/zdsock --program ${zope3_instance_home}/bin/runzope"

zope3_precmd() {
    for _dir in $required_dirs; do
    if test ! -d "${_dir}"; then
        err 1 "${_dir} is not a directory."
    fi
    done
    if test "${zope3_user}"; then
        command_args="${command_args} --user ${zope3_user}"
    fi
}

zope3_start() {
    ${command} ${rc_flags} ${command_args} start
}

zope3_stop() {
    ${command} ${rc_flags} ${command_args} stop
}

zope3_restart() {
    ${command} ${rc_flags} ${command_args} restart
}

zope3_status() {
    ${command} ${rc_flags} ${command_args} status
}

load_rc_config $name
run_rc_command "$1"
