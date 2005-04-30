#!/bin/sh
LINUX_KERN_OSREL=`/sbin/sysctl -n emul.linux.kern.osrelease 2>/dev/null`
if [ -z "$LINUX_KERN_OSREL" -o "$LINUX_KERN_OSREL" = "2.0.38" ]
then
 OPERADIR=$HOME/.opera
 mkdir -p $OPERADIR || exit 1
 for FILE in $OPERADIR/opera6.ini $OPERADIR/opera.ini
 do
  if [ -f ${FILE} ]
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
fi

unset LD_LIBRARY_PATH
exec @EMULDIR@/bin/bash /usr/bin/opera "$@"
