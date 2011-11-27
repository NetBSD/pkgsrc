$NetBSD: patch-src_nwc__dir.hh,v 1.1 2011/11/27 19:55:06 joerg Exp $

--- src/nwc_dir.hh.orig	2011-11-27 01:22:01.000000000 +0000
+++ src/nwc_dir.hh
@@ -27,6 +27,7 @@
 #include "nwc_fsentry.hh"
 
 #include <list>
+#include <memory>
 
 namespace NWC
 {
