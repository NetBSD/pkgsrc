$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_spinning__mutex.cc,v 1.3 2025/07/07 09:23:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/spinning_mutex.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/spinning_mutex.cc
@@ -19,7 +19,16 @@
 #endif
 
 #if PA_CONFIG(HAS_LINUX_KERNEL)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+#include <sys/time.h>
+#include <sys/futex.h>
+#elif defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/thr.h>
+#include <sys/umtx.h>
+#else
 #include <linux/futex.h>
+#endif
 #include <sys/syscall.h>
 #include <unistd.h>
 
@@ -92,8 +101,19 @@ PA_ALWAYS_INLINE long FutexSyscall(volat
   int saved_errno = errno;
   errno = 0;
 
+#if defined(OS_FREEBSD)
+  long retval = _umtx_op(&state_, UMTX_OP_WAIT_UINT_PRIVATE,
+                    kLockedContended, nullptr, nullptr);
+#elif defined(OS_OPENBSD)
+  long retval = futex(reinterpret_cast<volatile unsigned int *>(&state_), FUTEX_WAIT | FUTEX_PRIVATE_FLAG,
+                    kLockedContended, nullptr, nullptr);
+#elif defined(OS_NETBSD)
+  long retval = syscall(SYS___futex, reinterpret_cast<volatile int *>(&state_), op | FUTEX_PRIVATE_FLAG,
+                     value, nullptr, nullptr, 0, 0);
+#else
   long retval = syscall(SYS_futex, ftx, op | FUTEX_PRIVATE_FLAG, value, nullptr,
                         nullptr, 0);
+#endif
   if (retval == -1) {
     // These are programming errors, check them.
     PA_DCHECK((errno != EPERM) || (errno != EACCES) || (errno != EINVAL) ||
