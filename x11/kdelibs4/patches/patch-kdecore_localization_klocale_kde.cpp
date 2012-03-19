$NetBSD: patch-kdecore_localization_klocale_kde.cpp,v 1.1 2012/03/19 11:28:49 markd Exp $

--- kdecore/localization/klocale_kde.cpp.orig	2011-04-01 13:55:50.000000000 +0000
+++ kdecore/localization/klocale_kde.cpp
@@ -2516,7 +2516,7 @@ QByteArray KLocalePrivate::systemCodeset
 
     codeset = nl_langinfo(CODESET);
 
-    if ((codeset == "ANSI_X3.4-1968") || (codeset == "US-ASCII")) {
+    if ((codeset == "ANSI_X3.4-1968") || (codeset == "US-ASCII") || (codeset == "646")) {
         // means ascii, "C"; QTextCodec doesn't know, so avoid warning
         codeset = "ISO-8859-1";
     }
