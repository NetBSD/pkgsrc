$NetBSD: patch-third__party_perfetto_src_base_test_vm__test__utils.cc,v 1.9 2025/11/04 14:55:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/test/vm_test_utils.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ third_party/perfetto/src/base/test/vm_test_utils.cc
@@ -92,7 +92,7 @@ bool IsMapped(void* start, size_t size) 
   // Fuchsia doesn't yet support paging (b/119503290).
   ignore_result(page_size);
   return true;
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) || PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   // mincore isn't available on NaCL.
   ignore_result(page_size);
   return true;
