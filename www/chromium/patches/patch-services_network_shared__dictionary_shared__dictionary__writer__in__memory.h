$NetBSD: patch-services_network_shared__dictionary_shared__dictionary__writer__in__memory.h,v 1.22 2026/07/06 13:06:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/shared_dictionary/shared_dictionary_writer_in_memory.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ services/network/shared_dictionary/shared_dictionary_writer_in_memory.h
@@ -9,6 +9,8 @@
 #include <string>
 #include <vector>
 
+#include <vector>
+
 #include "base/component_export.h"
 #include "base/functional/callback.h"
 #include "crypto/hash.h"
