$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.12 2018/10/24 18:31:07 leot Exp $

- Add OS(SOLARIS) definition and add them to Unix systems.
- Avoid flock() on SunOS, not supported on older platforms.
- madvise(2) on {Free,Net,OpenBSD} support both MADV_DONTNEED and
  MADV_FREE.
- Add support for NetBSD.

--- Source/WTF/wtf/Platform.h.orig	2018-09-21 19:59:47.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -410,6 +410,11 @@
 #define WTF_OS_OPENBSD 1
 #endif
 
+/* OS(SOLARIS) - Solaris and derivatives */
+#ifdef __sun
+#define WTF_OS_SOLARIS 1
+#endif
+
 /* OS(WINDOWS) - Any version of Windows */
 #if defined(WIN32) || defined(_WIN32)
 #define WTF_OS_WINDOWS 1
@@ -427,6 +432,7 @@
     || OS(LINUX)            \
     || OS(NETBSD)           \
     || OS(OPENBSD)          \
+    || OS(SOLARIS)          \
     || defined(unix)        \
     || defined(__unix)      \
     || defined(__unix__)
@@ -567,8 +573,10 @@
 #define USE_HARFBUZZ 1
 #define USE_SOUP 1
 #define USE_WEBP 1
+#if !OS(SOLARIS)
 #define USE_FILE_LOCK 1
 #endif
+#endif
 
 #if PLATFORM(GTK)
 #define GLIB_VERSION_MIN_REQUIRED GLIB_VERSION_2_36
@@ -693,11 +701,16 @@
 
 #endif /* OS(DARWIN) */
 
+#if OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
+#define HAVE_MADV_FREE 1
+#define HAVE_MADV_DONTNEED 1
+#endif
+
 #if PLATFORM(COCOA)
 #define HAVE_CFNETWORK_STORAGE_PARTITIONING 1
 #endif
 
-#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
+#if OS(DARWIN) || OS(FUCHSIA) || ((OS(FREEBSD) || OS(NETBSD) || defined(__GLIBC__) || defined(__BIONIC__)) && (CPU(X86) || CPU(X86_64) || CPU(ARM) || CPU(ARM64) || CPU(MIPS)))
 #define HAVE_MACHINE_CONTEXT 1
 #endif
 
@@ -786,11 +799,11 @@
 
 #if !defined(ENABLE_DFG_JIT) && ENABLE(JIT)
 /* Enable the DFG JIT on X86 and X86_64. */
-#if (CPU(X86) || CPU(X86_64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(HURD) || OS(WINDOWS))
+#if (CPU(X86) || CPU(X86_64)) && (OS(DARWIN) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(HURD) || OS(WINDOWS))
 #define ENABLE_DFG_JIT 1
 #endif
 /* Enable the DFG JIT on ARMv7.  Only tested on iOS, Linux, and FreeBSD. */
-#if (CPU(ARM_THUMB2) || CPU(ARM64)) && (PLATFORM(IOS) || OS(LINUX) || OS(FREEBSD))
+#if (CPU(ARM_THUMB2) || CPU(ARM64)) && (PLATFORM(IOS) || OS(LINUX) || OS(FREEBSD) || OS(NETBSD))
 #define ENABLE_DFG_JIT 1
 #endif
 /* Enable the DFG JIT on ARM. */
