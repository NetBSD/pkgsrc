$NetBSD: patch-gwlib_log.c,v 1.1 2015/03/31 15:56:45 joerg Exp $

--- gwlib/log.c.orig	2015-03-29 10:51:48.000000000 +0000
+++ gwlib/log.c
@@ -432,13 +432,7 @@ static void PRINTFLIKE(1,0) kannel_syslo
     int translog;
     
     if (level >= sysloglevel && dosyslog) {
-	if (args == NULL) {
-	    strncpy(buf, format, sizeof(buf));
-	    buf[sizeof(buf) - 1] = '\0';
-	} else {
-	    vsnprintf(buf, sizeof(buf), format, args);
-	    /* XXX vsnprint not 100% portable */
-	}
+	vsnprintf(buf, sizeof(buf), format, args);
 
 	switch(level) {
 	case GW_DEBUG:
