$NetBSD: patch-src_searchd.cpp,v 1.1 2014/03/05 13:44:23 fhajny Exp $

Avoid hard-coded paths.

--- src/searchd.cpp.orig	2014-02-19 19:13:38.000000000 +0000
+++ src/searchd.cpp
@@ -19128,7 +19128,7 @@ void ShowHelp ()
 		"--safetrace\t\tonly use system backtrace() call in crash reports\n"
 		"\n"
 		"Examples:\n"
-		"searchd --config /usr/local/sphinx/etc/sphinx.conf\n"
+		"searchd --config @PKG_SYSCONFDIR@/sphinx.conf\n"
 #if USE_WINDOWS
 		"searchd --install --config c:\\sphinx\\sphinx.conf\n"
 #endif
