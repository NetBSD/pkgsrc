$NetBSD: patch-src_nwc__dir.hh,v 1.1 2025/06/07 17:09:35 vins Exp $

--- src/nwc_dir.hh.orig	2011-11-27 01:22:01.000000000 +0000
+++ src/nwc_dir.hh
@@ -27,6 +27,7 @@
 #include "nwc_fsentry.hh"
 
 #include <list>
+#include <memory>
 
 namespace NWC
 {
