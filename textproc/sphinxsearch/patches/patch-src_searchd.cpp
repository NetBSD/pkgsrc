$NetBSD: patch-src_searchd.cpp,v 1.3 2014/10/29 13:49:02 fhajny Exp $

Avoid hard-coded paths.

--- src/searchd.cpp.orig	2014-09-26 17:59:01.000000000 +0000
+++ src/searchd.cpp
@@ -21264,7 +21264,7 @@ void ShowHelp ()
 		"--safetrace\t\tonly use system backtrace() call in crash reports\n"
 		"\n"
 		"Examples:\n"
-		"searchd --config /usr/local/sphinx/etc/sphinx.conf\n"
+		"searchd --config @PKG_SYSCONFDIR@/sphinx.conf\n"
 #if USE_WINDOWS
 		"searchd --install --config c:\\sphinx\\sphinx.conf\n"
 #endif
