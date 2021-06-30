#! /bin/sh

VERS=v14.17.1

if [ "$1" = "-v" ] || [ "$1" = "--version" ]; then
	printf "${VERS}\n"
fi

exit 0
