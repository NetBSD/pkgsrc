$NetBSD: patch-src_pdfgrep.cc,v 1.1 2017/08/11 01:00:25 ryoon Exp $

* Run on non-C locale NetBSD environment

--- src/pdfgrep.cc.orig	2017-03-04 08:11:53.000000000 +0000
+++ src/pdfgrep.cc
@@ -428,7 +428,11 @@ int main(int argc, char** argv)
 	// Set locale to user-preference. If this locale is an UTF-8 locale, the
 	// regex-functions regcomp/regexec become unicode aware, which means
 	// e.g. that '.' will match a unicode character, not a single byte.
+	/* GCC from NetBSD base does not support C++ locale.
+	   See: http://gnats.netbsd.org/48291 */
+#if !defined(__NetBSD__)
 	locale::global(locale(""));
+#endif
 
 	enum re_engine_type {
 		RE_POSIX = 0,
