$NetBSD: patch-mail_app_nsMailApp.cpp,v 1.6 2013/01/07 21:55:30 ryoon Exp $

--- mail/app/nsMailApp.cpp.orig	2012-11-18 10:14:23.000000000 +0000
+++ mail/app/nsMailApp.cpp
@@ -12,6 +12,26 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #endif
+/*
+ * On netbsd-4, ulimit -n is 64 by default; too few for us.
+ */
+static void netbsd_fixrlimit(void) {
+	struct rlimit rlp;
+	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1) {
+		fprintf(stderr, "warning: getrlimit failed\n");
+		return;
+	}
+	if (rlp.rlim_cur >= 512)
+		return;
+	if (rlp.rlim_max < 512) {
+		fprintf(stderr, "warning: hard limit of 'ulimit -n' too low\n");
+		rlp.rlim_cur = rlp.rlim_max;
+	}
+	else
+		rlp.rlim_cur = 512;
+	if (setrlimit(RLIMIT_NOFILE, &rlp) == -1)
+		fprintf(stderr, "warning: setrlimit failed\n");
+	}
 
 #ifdef XP_MACOSX
 #include "MacQuirks.h"
@@ -115,6 +135,7 @@ static int do_main(const char *exePath, 
 
 int main(int argc, char* argv[])
 {
+  netbsd_fixrlimit();
   char exePath[MAXPATHLEN];
 
 #ifdef XP_MACOSX
