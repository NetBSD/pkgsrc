$NetBSD: patch-src_searchd.cpp,v 1.2 2014/10/17 17:28:15 fhajny Exp $

Avoid hard-coded paths.

--- src/searchd.cpp.orig	2014-09-26 17:59:01.000000000 +0000
+++ src/searchd.cpp
@@ -21264,7 +21264,7 @@ void ShowHelp ()
 		"--safetrace\t\tonly use system backtrace() call in crash reports\n"
 		"\n"
 		"Examples:\n"
-		"searchd --config /usr/local/sphinx/etc/sphinx.conf\n"
+		"searchd --config /opt/local/etc/sphinx.conf\n"
 #if USE_WINDOWS
 		"searchd --install --config c:\\sphinx\\sphinx.conf\n"
 #endif
