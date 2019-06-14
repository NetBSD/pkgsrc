$NetBSD: patch-autogen.sh,v 1.3 2019/06/14 02:09:03 gutteridge Exp $

Work around gettext version mismatches (e.g., 0.20.1 would cause this to
break, because there are no infrastructure files for that version number
for autopoint to locate). The intent to override seems unnecessary for
pkgsrc's purposes.

--- autogen.sh.orig	2018-10-31 08:44:56.000000000 +0000
+++ autogen.sh
@@ -26,9 +26,6 @@ if [ -x "`which git 2>/dev/null`" -a -d 
 	       s:%%VERSION%%:$VERSION:g
 	       s:%%DATE%%:$DATE:g
 	       s:%%BRANCH%%:$BRANCH:g"
-else
-	sed -i.bak configure.ac -r \
-		-e "s:^AM_GNU_GETTEXT_VERSION.*:AM_GNU_GETTEXT_VERSION([$GTVERSION]):"
 fi
 
 mkdir m4 2>/dev/null
