#!/bin/sh
OPERADIR=$HOME/.opera

mkdir -p $OPERADIR || exit 1
for FILE in $OPERADIR/opera.ini $OPERADIR/opera5.ini
do
 if [ -e ${FILE} ]
 then
  if grep -q '^Synchronous DNS Lookup=0$' ${FILE}
  then
   cp -p ${FILE} ${FILE}.patch
   sed -e 's#^\(Synchronous DNS Lookup\)=0$#\1=1#' ${FILE}.patch >${FILE}
   rm -f ${FILE}.patch
  fi
 else
  echo >${FILE} "[Performance]"
  echo >>${FILE} "Synchronous DNS Lookup=1"
 fi
done

exec @EMULDIR@/bin/bash /usr/bin/opera "$@"
