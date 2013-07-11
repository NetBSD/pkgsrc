$NetBSD: patch-String.hpp,v 1.1 2013/07/11 14:05:14 sborrill Exp $

Fix build with 64-bit time_t
--- String.hpp.orig	2013-07-11 14:41:21.000000000 +0100
+++ String.hpp	2013-07-11 14:41:38.000000000 +0100
@@ -38,6 +38,7 @@
     String(const String& s);
     String(const int num);
     String(const long num);
+    String(const long long num);
     String(const char bs[], int len);
     String(const char bs[], int start, int len);
     friend ostream &  operator << (ostream & out, const String& s);
