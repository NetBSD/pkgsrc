$NetBSD: patch-src_3rdparty_chromium_third__party_swiftshader_src_Vulkan_VkSemaphoreExternalLinux.hpp,v 1.1 2025/12/21 09:38:44 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/swiftshader/src/Vulkan/VkSemaphoreExternalLinux.hpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/src/Vulkan/VkSemaphoreExternalLinux.hpp
@@ -49,13 +49,17 @@ public:
 	{
 		pthread_mutexattr_t mattr;
 		pthread_mutexattr_init(&mattr);
+#if 0
 		pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
+#endif
 		pthread_mutex_init(&mutex, &mattr);
 		pthread_mutexattr_destroy(&mattr);
 
 		pthread_condattr_t cattr;
 		pthread_condattr_init(&cattr);
+#if 0
 		pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
+#endif
 		pthread_cond_init(&cond, &cattr);
 		pthread_condattr_destroy(&cattr);
 	}
