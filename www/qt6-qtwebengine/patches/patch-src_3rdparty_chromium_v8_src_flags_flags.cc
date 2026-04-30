$NetBSD: patch-src_3rdparty_chromium_v8_src_flags_flags.cc,v 1.2 2026/04/30 06:39:46 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/v8/src/flags/flags.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/v8/src/flags/flags.cc
@@ -16,6 +16,10 @@
 #include <set>
 #include <sstream>
 
+#if V8_OS_OPENBSD
+#include <sys/mman.h>
+#endif
+
 #include "src/base/fpu.h"
 #include "src/base/hashing.h"
 #include "src/base/lazy-instance.h"
@@ -827,6 +831,10 @@ void FlagList::FreezeFlags() {
   // Note that for string flags we only protect the pointer itself, but not the
   // string storage. TODO(12887): Fix this.
   base::OS::SetDataReadOnly(&v8_flags, sizeof(v8_flags));
+#if V8_OS_OPENBSD
+  if (mimmutable(&v8_flags, sizeof(v8_flags)) == -1)
+    FATAL("unable to set immutability of v8_flags");
+#endif
 }
 
 // static
