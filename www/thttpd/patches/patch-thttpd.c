$NetBSD: patch-thttpd.c,v 1.1 2026/09/25 14:20:40 wiz Exp $

Not a CVE: the access log is created world-readable.  Both places that
open it use fopen(logfile, "a"), so a log that does not exist yet is
created 0666 & ~umask -- 0644 under the usual umask.  Every line holds
the request line, the Referer and the User-Agent, and on an
authenticated directory the remote user name, so it should not be
readable by every local user.  This matters most after log rotation,
where the file is gone and thttpd recreates it on SIGHUP.

Created with 0640 instead.  open() rather than a chmod() after fopen()
so that there is no window in which the file exists with the wider
mode, and so that a log the administrator already created keeps the
mode they chose -- a chmod() would overwrite it on every start.

FreeBSD ports and Fedora both fix this, but with a chmod() after the
fopen(): FreeBSD to 0640, Fedora to 0600.  Fedora additionally disables
the fchown() below, which stops thttpd handing the log to the user it
drops privileges to, so it cannot re-open the log afterwards.  The
fchown() is left alone here.

--- thttpd.c.orig
+++ thttpd.c
@@ -327,6 +327,25 @@
     }
 
 
+/* Open the log file for appending.  A log that has to be created is created
+** without the world-readable bit: every line holds the request, the Referer
+** and the User-Agent, and on an authenticated directory the remote user name.
+** A file that already exists keeps the mode the administrator gave it.  This
+** uses open() rather than fopen() so that there is no window in which the
+** file exists with the wider mode.
+*/
+static FILE*
+open_logfile( char* lf )
+    {
+    int fd;
+
+    fd = open( lf, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP );
+    if ( fd < 0 )
+	return (FILE*) 0;
+    return fdopen( fd, "a" );
+    }
+
+
 static void
 re_open_logfile( void )
     {
@@ -339,7 +358,7 @@
     if ( logfile != (char*) 0 && strcmp( logfile, "-" ) != 0 )
 	{
 	syslog( LOG_NOTICE, "re-opening logfile" );
-	logfp = fopen( logfile, "a" );
+	logfp = open_logfile( logfile );
 	if ( logfp == (FILE*) 0 )
 	    {
 	    syslog( LOG_CRIT, "re-opening %.80s - %m", logfile );
@@ -428,7 +447,7 @@
 	    logfp = stdout;
 	else
 	    {
-	    logfp = fopen( logfile, "a" );
+	    logfp = open_logfile( logfile );
 	    if ( logfp == (FILE*) 0 )
 		{
 		syslog( LOG_CRIT, "%.80s - %m", logfile );
