#! /bin/sh

VERS=v23.7.0

if [ "$1" = "-v" ] || [ "$1" = "--version" ]; then
	printf "${VERS}\n"
fi

exit 0
