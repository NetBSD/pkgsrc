#!/bin/sh
#
# $NetBSD: horde_setup.sh,v 1.1.1.1 2001/02/12 15:26:04 jlam Exp $

HORDEDIR=@HORDEDIR@

for file in config/horde.php3 imp/config/defaults.php3
do
	if [ ! -e ${HORDEDIR}/${file} ]
	then
		echo "${HORDEDIR}/${file} could not be found."
		exit 1
	fi
	chmod a+rw ${HORDEDIR}/${file}
done

cat << EOF

Horde/IMP may now by configured by pointing a web browser at:

	http://localhost/horde/setup.php3

Please run 'horde_secure' after configuration is complete to re-protect
the Horde configuration files.

EOF
exit 0
