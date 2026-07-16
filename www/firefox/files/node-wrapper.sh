#! /bin/sh

VERS=v26.5.0

if [ "$1" = "-v" ] || [ "$1" = "--version" ]; then
	printf "${VERS}\n"
fi

exit 0
