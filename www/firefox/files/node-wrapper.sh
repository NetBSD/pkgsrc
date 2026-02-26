#! /bin/sh

VERS=v25.6.1

if [ "$1" = "-v" ] || [ "$1" = "--version" ]; then
	printf "${VERS}\n"
fi

exit 0
