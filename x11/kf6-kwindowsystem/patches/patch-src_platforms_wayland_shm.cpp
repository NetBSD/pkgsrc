$NetBSD: patch-src_platforms_wayland_shm.cpp,v 1.1 2024/05/26 13:45:28 markd Exp $

fd not declared if not defined HAVE_MEMFD

--- src/platforms/wayland/shm.cpp.orig	2024-02-21 11:27:59.000000000 +0000
+++ src/platforms/wayland/shm.cpp
@@ -78,8 +78,9 @@ std::unique_ptr<ShmBuffer> Shm::createBu
     const int stride = image.bytesPerLine();
     const int32_t byteCount = image.size().height() * stride;
 
+    int fd;
 #if defined HAVE_MEMFD
-    int fd = memfd_create("kwayland-shared", MFD_CLOEXEC | MFD_ALLOW_SEALING);
+    fd = memfd_create("kwayland-shared", MFD_CLOEXEC | MFD_ALLOW_SEALING);
     if (fd >= 0) {
         fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_SEAL);
     } else
