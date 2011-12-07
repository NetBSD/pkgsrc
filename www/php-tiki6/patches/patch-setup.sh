$NetBSD: patch-setup.sh,v 1.1.1.1 2011/12/07 13:29:39 ryoon Exp $

--- setup.sh.orig	2011-05-06 16:37:00.000000000 +0000
+++ setup.sh
@@ -163,7 +163,7 @@ what to answer, just press enter to each
 	if [ "$USER" = 'root' ]; then
 		chmod -R g+w $DIRS
 	else
-		chmod -fR go+w $DIRS
+		chmod -fR g+w $DIRS
 	fi
 
 #	chmod 664 robots.txt tiki-install.php
