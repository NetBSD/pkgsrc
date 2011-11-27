$NetBSD: patch-src_nwc__dir.cc,v 1.1 2011/11/27 19:55:06 joerg Exp $

--- src/nwc_dir.cc.orig	2011-11-27 01:22:19.000000000 +0000
+++ src/nwc_dir.cc
@@ -23,6 +23,7 @@
 #include "nwc_file.hh"
 #include "nwc_path.hh"
 #include <iostream>
+#include <typeinfo>
 
 namespace NWC
 {
