$NetBSD: patch-third__party_vulkan-validation-layers_src_layers_external_vma_vk__mem__alloc.h,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h
@@ -2971,7 +2971,7 @@ static void* vma_aligned_alloc(size_t al
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <cstdlib>
 
 #if defined(__APPLE__)
