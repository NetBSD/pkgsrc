$NetBSD: patch-src_node__type.h,v 1.1 2024/02/01 09:20:02 wiz Exp $

Fix build with libxml2 2.12.
https://github.com/lwindolf/liferea/commit/d8f8ff91c6a243d67a6783b3d95bbdbffb0aeaef

--- src/node_type.h.orig	2024-02-01 09:18:50.907905086 +0000
+++ src/node_type.h
@@ -23,6 +23,7 @@
 
 #include "node.h"
 
+#include <libxml/tree.h>
 #include <libxml/xmlmemory.h>
 #include <gtk/gtk.h>
 
