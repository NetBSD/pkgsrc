#! /bin/sh

VERS=v22.2.0

if [ "$1" = "-v" ] || [ "$1" = "--version" ]; then
	printf "${VERS}\n"
fi

exit 0
