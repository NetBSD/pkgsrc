$NetBSD: patch-mozilla_ipc_chromium_src_chrome_common_file__descriptor__set__posix.h,v 1.3 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/chromium/src/chrome/common/file_descriptor_set_posix.h.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/chromium/src/chrome/common/file_descriptor_set_posix.h
@@ -30,7 +30,7 @@ class FileDescriptorSet : public base::R
   // In debugging mode, it's a fatal error to try and add more than this number
   // of descriptors to a FileDescriptorSet.
   enum {
-    MAX_DESCRIPTORS_PER_MESSAGE = 4,
+    MAX_DESCRIPTORS_PER_MESSAGE = 4
   };
 
   // ---------------------------------------------------------------------------
