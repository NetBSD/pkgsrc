$NetBSD: patch-third__party_swiftshader_src_Vulkan_VkSemaphoreExternalLinux.hpp,v 1.17 2026/04/10 17:32:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/src/Vulkan/VkSemaphoreExternalLinux.hpp.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/swiftshader/src/Vulkan/VkSemaphoreExternalLinux.hpp
@@ -50,13 +50,17 @@ public:
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
