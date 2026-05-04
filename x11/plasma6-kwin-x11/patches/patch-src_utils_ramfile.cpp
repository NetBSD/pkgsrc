$NetBSD: patch-src_utils_ramfile.cpp,v 1.1 2026/05/04 11:08:21 markd Exp $

Follow OpenBSD in commenting out some code that doesn't build

--- src/utils/ramfile.cpp.orig	2025-11-04 14:59:51.000000000 +0000
+++ src/utils/ramfile.cpp
@@ -78,6 +78,7 @@ RamFile::RamFile(const char *name, const
     m_tmp->unmap(data);
 #endif
 
+    /*
     int seals = F_SEAL_SHRINK | F_SEAL_GROW | F_SEAL_SEAL;
     if (flags.testFlag(RamFile::Flag::SealWrite)) {
         seals |= F_SEAL_WRITE;
@@ -86,6 +87,7 @@ RamFile::RamFile(const char *name, const
     if (fcntl(fd(), F_ADD_SEALS, seals) != 0) {
         qCDebug(KWIN_CORE).nospace() << name << ": Failed to seal RamFile: " << strerror(errno);
     }
+    */
 
     guard.dismiss();
 }
@@ -137,12 +139,14 @@ RamFile::Flags RamFile::effectiveFlags()
 {
     Flags flags = {};
 
+    /*
     const int seals = fcntl(fd(), F_GET_SEALS);
     if (seals > 0) {
         if (seals & F_SEAL_WRITE) {
             flags.setFlag(Flag::SealWrite);
         }
     }
+    */
 
     return flags;
 }
