$NetBSD: patch-modes_dclock.c,v 1.2.2.2 2012/10/17 19:22:10 tron Exp $

--- modes/dclock.c.orig	2012-01-23 13:19:21.000000000 +0000
+++ modes/dclock.c
@@ -420,7 +420,7 @@ convert(double x, char *string)
 }
 
 static void
-dayhrminsec(long timeCount, int tzoffset, char *string)
+dayhrminsec(time_t timeCount, int tzoffset, char *string)
 {
 	int days, hours, minutes, secs;
 	int bufsize, i;
@@ -675,7 +675,7 @@ drawDclock(ModeInfo * mi)
 				"%a %b %d %Y", localtime(&(dp->timeold)));
 		}
 	  } else {
-		long timeNow, timeLocal;
+		time_t timeNow, timeLocal;
 		timeNow = seconds();
 		timeLocal = timeNow + dp->tzoffset;
 
@@ -950,7 +950,7 @@ init_dclock(ModeInfo * mi)
 {
 	Display *display = MI_DISPLAY(mi);
 	dclockstruct *dp;
-	long timeNow, timeLocal;
+	time_t timeNow, timeLocal;
 	int i, j;
 
 	if (dclocks == NULL) {
@@ -1252,7 +1252,7 @@ defined(MODE_dclock_mayan)
 			dayhrminsec(MAYAN_TIME_START - timeLocal, dp->tzoffset, dp->strnew[1]);
 			dp->strpta[1] = dp->strnew[1];
 		} else {
-			struct tm *t = localtime((const time_t *) &timeLocal);
+			struct tm *t = localtime(&timeLocal);
 
 			if (dp->time24)
 			  (void) strftime(dp->strnew[0], STRSIZE, "%H:%M:%S", t);
