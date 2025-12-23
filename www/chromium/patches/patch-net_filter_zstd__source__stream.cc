$NetBSD: patch-net_filter_zstd__source__stream.cc,v 1.13 2025/12/23 13:22:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/filter/zstd_source_stream.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ net/filter/zstd_source_stream.cc
@@ -7,6 +7,7 @@
 #include <algorithm>
 #include <unordered_map>
 #include <utility>
+#include <unordered_map>
 
 #define ZSTD_STATIC_LINKING_ONLY
 
