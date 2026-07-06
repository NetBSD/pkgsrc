$NetBSD: patch-v8_src_flags_flags.cc,v 1.22 2026/07/06 13:07:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/flags/flags.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ v8/src/flags/flags.cc
@@ -17,6 +17,10 @@
 #include <sstream>
 #include <unordered_map>
 
+#if V8_OS_OPENBSD
+#include <sys/mman.h>
+#endif
+
 #include "src/base/fpu.h"
 #include "src/base/hashing.h"
 #include "src/base/lazy-instance.h"
@@ -887,6 +891,10 @@ void FlagList::FreezeFlags() {
   // Note that for string flags we only protect the pointer itself, but not the
   // string storage. TODO(12887): Fix this.
   base::OS::SetDataReadOnly(&v8_flags, sizeof(v8_flags));
+#if V8_OS_OPENBSD
+  if (mimmutable(&v8_flags, sizeof(v8_flags)) == -1)
+    FATAL("unable to set immutability of v8_flags");
+#endif
 }
 
 // static
