$NetBSD: patch-copyout.cc,v 1.1 2020/03/30 19:35:19 joerg Exp $

--- copyout.cc.orig	2020-03-29 22:39:59.674899981 +0000
+++ copyout.cc
@@ -132,7 +132,7 @@ copy_out( size_t filesize, size_t metasi
   static const char* index = "index.html";
   
   // find hostname part after the scheme (okok, not counting port, etc.)
-  char* ptr = strstr( url, "://" );
+  const char* ptr = strstr( url, "://" );
   if ( ptr == 0 || strlen(ptr) < 4 ) return false;
 
   // create filename to store contents into
