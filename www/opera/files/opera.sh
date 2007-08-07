#!@SH@
#
# $NetBSD: opera.sh,v 1.4 2007/08/07 21:37:25 jlam Exp $
#
# This script is used with linux-* emulations to ensure that opera is
# started with the proper environment.
#

#
# fixup_opera_ini
#	This corrects opera.ini and opera6.ini files in the user's
#	$HOME directory to enable synchronous DNS lookups on older
#	versions of NetBSD.
#
fixup_opera_ini()
{
	linux_osrel=`/sbin/sysctl -n emul.linux.kern.osrelease 2>/dev/null`
	case "$linux_osrel" in
	[01].*|2.0|2.0.[0-9]|2.0.[12][0-9]|2.0.3[0-8])
		# On older NetBSD (linux kernel emulation <= 2.0.38),
		# synchronous DNS lookups need to be explicitly enabled.
		;;
	*)	return 0 ;;
	esac

	OPERADIR=$HOME/.opera
	@MKDIR@ $OPERADIR || return 1
	for inifile in $OPERADIR/opera6.ini $OPERADIR/opera.ini; do
		if [ ! -f $inifile ]; then
			echo >$inifile  "[Performance]"
			echo >>$inifile "Synchronous DNS Lookup=1"
			continue
		fi
		@SED@ "s/^\(Synchronous DNS Lookup\)=0/\1=1/" \
			$inifile > $inifile.patched
		if @CMP@ -s $inifile $inifile.patched; then
			@RM@ -f $inifile.patched
		else
			@MV@ -f $inifile.patched $inifile
		fi
	done
	return 0
}

fixup_opera_ini || exit 1

# Fix up LD_LIBRARY_PATH so that /lib is always searched for shared
# libraries.
#
LD_LIBRARY_PATH=/lib:/usr/lib; export LD_LIBRARY_PATH

exec @EMULDIR@/bin/bash /usr/bin/opera "$@"
