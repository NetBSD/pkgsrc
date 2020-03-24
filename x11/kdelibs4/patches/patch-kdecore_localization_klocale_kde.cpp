$NetBSD: patch-kdecore_localization_klocale_kde.cpp,v 1.2 2020/03/24 20:34:31 joerg Exp $

--- kdecore/localization/klocale_kde.cpp.orig	2017-11-05 01:51:22.000000000 +0000
+++ kdecore/localization/klocale_kde.cpp
@@ -2438,8 +2438,8 @@ QString KLocalePrivate::formatLocaleTime
 
 bool KLocalePrivate::use12Clock() const
 {
-    if ((timeFormat().contains(QString::fromLatin1("%I")) > 0) ||
-        (timeFormat().contains(QString::fromLatin1("%l")) > 0)) {
+    if ((timeFormat().contains(QString::fromLatin1("%I")) != 0) ||
+        (timeFormat().contains(QString::fromLatin1("%l")) != 0)) {
         return true;
     } else {
         return false;
@@ -2657,7 +2657,7 @@ QByteArray KLocalePrivate::systemCodeset
 
     codeset = nl_langinfo(CODESET);
 
-    if ((codeset == "ANSI_X3.4-1968") || (codeset == "US-ASCII")) {
+    if ((codeset == "ANSI_X3.4-1968") || (codeset == "US-ASCII") || (codeset == "646")) {
         // means ascii, "C"; QTextCodec doesn't know, so avoid warning
         codeset = "ISO-8859-1";
     }
