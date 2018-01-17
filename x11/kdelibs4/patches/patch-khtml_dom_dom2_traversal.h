$NetBSD: patch-khtml_dom_dom2_traversal.h,v 1.1 2018/01/17 18:53:25 markd Exp $

Build with gcc6 - from ArchLinux

--- khtml/dom/dom2_traversal.h.orig	2015-12-08 15:49:30.000000000 +0000
+++ khtml/dom/dom2_traversal.h
@@ -214,7 +214,7 @@ public:
      *
      */
     enum ShowCode {
-        SHOW_ALL                       = 0xFFFFFFFF,
+        SHOW_ALL                       = (int)0xFFFFFFFF,
         SHOW_ELEMENT                   = 0x00000001,
         SHOW_ATTRIBUTE                 = 0x00000002,
         SHOW_TEXT                      = 0x00000004,
