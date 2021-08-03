$NetBSD: patch-src_3rdparty_chromium_third__party_leveldatabase_env__chromium.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/leveldatabase/env_chromium.cc.orig	2020-07-15 18:56:31.000000000 +0000
+++ src/3rdparty/chromium/third_party/leveldatabase/env_chromium.cc
@@ -37,7 +37,7 @@
 #include "third_party/leveldatabase/leveldb_chrome.h"
 #include "third_party/leveldatabase/leveldb_features.h"
 #include "third_party/leveldatabase/src/include/leveldb/options.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 using base::FilePath;
 using base::trace_event::MemoryAllocatorDump;
