$NetBSD: patch-aclocal.m4,v 1.1 2018/10/31 14:56:40 jperkin Exp $

Don't quote ${EGREP}, it may be set to "grep -E".

--- aclocal.m4.orig	2018-06-01 09:42:18.000000000 +0000
+++ aclocal.m4
@@ -1,6 +1,6 @@
 AC_DEFUN(AC_SET_VANILLA_FLAG,
  [dnl Determine arguments to run Emacs as vanilla.
-  retval=`echo "${EMACS}"| "${EGREP}" xemacs| "${EGREP}" -v '^$'`
+  retval=`echo "${EMACS}"| ${EGREP} xemacs| ${EGREP} -v '^$'`
   if test -z "${retval}"; then
 	VANILLA_FLAG="-q -no-site-file"
   else
@@ -248,9 +248,9 @@ AC_DEFUN(AC_ADD_LOAD_PATH,
 	ADDITIONAL_LOAD_PATH="${withval}"
       else
 	if test x"$USER" != xroot -a x"$HOME" != x -a -f "$HOME"/.emacs; then
-          ADDITIONAL_LOAD_PATH=`${XEMACSDEBUG} \'${EMACS}\' -batch -l \'$HOME/.emacs\' -l w3mhack.el NONE -f w3mhack-load-path 2>/dev/null | \'${EGREP}\' -v \'^$\'`
+          ADDITIONAL_LOAD_PATH=`${XEMACSDEBUG} \'${EMACS}\' -batch -l \'$HOME/.emacs\' -l w3mhack.el NONE -f w3mhack-load-path 2>/dev/null | ${EGREP} -v \'^$\'`
         else
-          ADDITIONAL_LOAD_PATH=`${XEMACSDEBUG} \'${EMACS}\' -batch -l w3mhack.el NONE -f w3mhack-load-path 2>/dev/null | \'${EGREP}\' -v \'^$\'`
+          ADDITIONAL_LOAD_PATH=`${XEMACSDEBUG} \'${EMACS}\' -batch -l w3mhack.el NONE -f w3mhack-load-path 2>/dev/null | ${EGREP} -v \'^$\'`
         fi
       fi
       AC_MSG_RESULT(${ADDITIONAL_LOAD_PATH})],
@@ -265,7 +265,7 @@ AC_DEFUN(AC_ADD_LOAD_PATH,
         ADDITIONAL_LOAD_PATH="${ADDITIONAL_LOAD_PATH}:`pwd`/attic"
       fi
     fi])
-  retval=`eval "${XEMACSDEBUG} '${EMACS}' ${VANILLA_FLAG} -batch -l w3mhack.el '${ADDITIONAL_LOAD_PATH}' -f w3mhack-print-status 2>/dev/null | '${EGREP}' -v '^$'"`
+  retval=`eval "${XEMACSDEBUG} '${EMACS}' ${VANILLA_FLAG} -batch -l w3mhack.el '${ADDITIONAL_LOAD_PATH}' -f w3mhack-print-status 2>/dev/null | ${EGREP} -v '^$'"`
   if test x"$retval" != xOK; then
     AC_MSG_ERROR([Process couldn't proceed.  See the above messages.])
   fi
