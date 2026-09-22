$NetBSD: patch-v8_src_flags_flags.cc,v 1.26 2026/09/22 13:41:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/flags/flags.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ v8/src/flags/flags.cc
@@ -19,6 +19,10 @@
 #include <unordered_map>
 #include <vector>
 
+#if V8_OS_OPENBSD
+#include <sys/mman.h>
+#endif
+
 #include "src/base/fpu.h"
 #include "src/base/hashing.h"
 #include "src/base/lazy-instance.h"
@@ -983,6 +987,10 @@ void FlagList::FreezeFlags() {
   // Note that for string flags we only protect the pointer itself, but not the
   // string storage. TODO(12887): Fix this.
   base::OS::SetDataReadOnly(&v8_flags, sizeof(v8_flags));
+#if V8_OS_OPENBSD
+  if (mimmutable(&v8_flags, sizeof(v8_flags)) == -1)
+    FATAL("unable to set immutability of v8_flags");
+#endif
 }
 
 // static
