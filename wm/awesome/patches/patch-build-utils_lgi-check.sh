$NetBSD: patch-build-utils_lgi-check.sh,v 1.1 2013/12/08 00:18:21 dholland Exp $

For some reason (probably cmake's doing) setting AWESOME_IGNORE_LGI=1
from pkgsrc does not prevent this from failing the build, so do it
forcibly.

--- build-utils/lgi-check.sh~	2013-04-01 11:44:46.000000000 +0000
+++ build-utils/lgi-check.sh
@@ -14,7 +14,7 @@ die()
 	echo " Add AWESOME_IGNORE_LGI=1 to your environment to continue."
 	echo
 	echo
-	if [ "x$AWESOME_IGNORE_LGI" = "x1" ]
+	if true;
 	then
 		exit 0
 	fi
