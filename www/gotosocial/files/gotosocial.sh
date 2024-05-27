#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gotosocial.sh,v 1.2 2024/05/27 20:04:46 nikita Exp $
#
# PROVIDE: gotosocial
# REQUIRE: NETWORKING DAEMON
# KEYWORD: chrootdir

if @TEST@ -f @SYSCONFBASE@/rc.subr; then
	. @SYSCONFBASE@/rc.subr
fi

name="gotosocial"
rcvar=${name}

command="@PREFIX@/bin/gotosocial"
: ${gotosocial_config:=@PKG_SYSCONFDIR@/config.yaml}
command_args="--config-path ${gotosocial_config} server start 2>&1 | logger -t ${name} -p daemon.info &"
required_files="${gotosocial_config}"

start_precmd="gotosocial_precmd"

gotosocial_precmd()
{
	if ! @TEST@ -f ${required_files}; then
		warn "${required_files} does not exist."
		return 1
	fi
	if ! @TEST@ -d @GOTOSOCIAL_CHROOT@; then
		@MKDIR@ -m 0755 @GOTOSOCIAL_CHROOT@
	fi
	if ! @TEST@ -f @GOTOSOCIAL_DB@; then
		@MKDIR@ -m 0755 @GOTOSOCIAL_DB@
	fi
	if ! @TEST@ -f @GOTOSOCIAL_DATA@; then
		@MKDIR@ -m 0755 @GOTOSOCIAL_DATA@
	fi
	if ! @TEST@ -f @GOTOSOCIAL_DB@/storage/certs; then
		@MKDIR@ -m 0755 @GOTOSOCIAL_DB@/storage/certs
	fi
	@CHOWN@ @GOTOSOCIAL_USER@:@GOTOSOCIAL_GROUP@ @GOTOSOCIAL_CHROOT@
	# @CHOWN@ @GOTOSOCIAL_USER@:@GOTOSOCIAL_GROUP@ @GOTOSOCIAL_DATA@
	@CP@ -R @EGDIR@/web/assets @GOTOSOCIAL_DATA@
	#@CP@ -R @EGDIR@/web/source @GOTOSOCIAL_DATA@
	@CP@ -R @EGDIR@/web/template @GOTOSOCIAL_DATA@
}

load_rc_config $name
run_rc_command "$1"
