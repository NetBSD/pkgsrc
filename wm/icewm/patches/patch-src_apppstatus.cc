$NetBSD: patch-src_apppstatus.cc,v 1.1 2012/11/16 20:07:48 joerg Exp $

--- src/apppstatus.cc.orig	2012-11-16 19:21:16.000000000 +0000
+++ src/apppstatus.cc
@@ -81,7 +81,9 @@ NetStatus::NetStatus(char const * netdev
 
 NetStatus::~NetStatus() {
     delete[] fNetDev;
-    delete[] color;
+    delete color[0];
+    delete color[1];
+    delete color[2];
     delete[] ppp_in;
     delete[] ppp_out;
     delete fUpdateTimer;
