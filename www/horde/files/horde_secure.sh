#!/bin/sh
#
# $NetBSD: horde_secure.sh,v 1.1.1.1 2001/02/12 15:26:04 jlam Exp $

HORDEDIR=@HORDEDIR@

for file in config/horde.php3 imp/config/defaults.php3
do
	if [ ! -e ${HORDEDIR}/${file} ]
	then
		echo "${HORDEDIR}/${file} could not be found."
		exit 1
	fi
	chmod 444 ${HORDEDIR}/${file}
done

for file in setup.php3 test.php3
do
	if [ ! -e ${HORDEDIR}/${file} ]
	then
		echo "${HORDEDIR}/${file} could not be found."
		exit 1
	fi
	chmod 000 ${HORDEDIR}/${file}
done

cat << EOF

The Horde/IMP configuration files have been set to read-only, and the
setup and test pages have been set to no-access.

EOF
exit 0
