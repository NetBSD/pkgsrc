$NetBSD: patch-third__party_swiftshader_src_System_Linux_MemFd.cpp,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/src/System/Linux/MemFd.cpp.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/swiftshader/src/System/Linux/MemFd.cpp
@@ -25,6 +25,7 @@
 #	define MFD_CLOEXEC 0x0001U
 #endif
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #if __aarch64__
 #	define __NR_memfd_create 279
 #elif __arm__
@@ -36,6 +37,7 @@
 #elif __x86_64__
 #	define __NR_memfd_create 319
 #endif /* __NR_memfd_create__ */
+#endif
 
 LinuxMemFd::~LinuxMemFd()
 {
@@ -63,13 +65,17 @@ bool LinuxMemFd::allocate(const char *na
 {
 	close();
 
-#ifndef __NR_memfd_create
+#if !defined(__NR_memfd_create) || defined(__OpenBSD__)
 	TRACE("memfd_create() not supported on this system!");
 	return false;
 #else
 	// In the event of no system call this returns -1 with errno set
 	// as ENOSYS.
+#if defined(__FreeBSD__) ||  defined(__NetBSD__)
+	fd_ = memfd_create(name, MFD_CLOEXEC);
+#else
 	fd_ = syscall(__NR_memfd_create, name, MFD_CLOEXEC);
+#endif
 	if(fd_ < 0)
 	{
 		TRACE("memfd_create() returned %d: %s", errno, strerror(errno));
