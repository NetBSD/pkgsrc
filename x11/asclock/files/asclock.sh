#!/bin/sh
#
# $NetBSD: asclock.sh,v 1.1 1999/10/28 19:04:57 jlam Exp $

args=''
while [ $# -gt 0 ]
do
	case $1 in
	-lang)
		LANG=$2; shift
		if [ -z "${LANG}" ]
		then
			echo "asclock: -lang needs a language option"
			quit 1
		fi
		;;
	*)
		args="${args} $1"
		;;
	esac
	shift
done

ASCLOCKDIR=@PREFIX@/share/asclock

# default to American English
if [ -z "${LANG}" -o ! -d ${ASCLOCKDIR}/${LANG} ]
then
	LANG=en
fi

monthxpm=${ASCLOCKDIR}/${LANG}/month.xpm
weekdayxpm=${ASCLOCKDIR}/${LANG}/weekday.xpm

args="${args} -monthxpm ${monthxpm} -weekdayxpm ${weekdayxpm}"
exec @PREFIX@/libexec/asclock ${args}
