$NetBSD: patch-services_network_shared__dictionary_shared__dictionary__writer__in__memory.h,v 1.3 2025/07/07 09:23:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/shared_dictionary/shared_dictionary_writer_in_memory.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ services/network/shared_dictionary/shared_dictionary_writer_in_memory.h
@@ -9,6 +9,8 @@
 #include <string>
 #include <vector>
 
+#include <vector>
+
 #include "base/component_export.h"
 #include "base/functional/callback.h"
 #include "crypto/secure_hash.h"
