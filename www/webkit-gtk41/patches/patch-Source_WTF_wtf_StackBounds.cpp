$NetBSD: patch-Source_WTF_wtf_StackBounds.cpp,v 1.1 2026/08/30 14:25:05 wiz Exp $

--- Source/WTF/wtf/StackBounds.cpp.orig	2026-02-23 14:40:54.556305400 +0000
+++ Source/WTF/wtf/StackBounds.cpp
@@ -42,6 +42,14 @@
 #include <unistd.h>
 #endif
 
+#if OS(NETBSD)
+#include <sys/exec.h>
+#include <sys/param.h>
+#include <sys/resource.h>
+#include <unistd.h>
+extern "C" struct ps_strings* __ps_strings;
+#endif
+
 #if OS(QNX)
 #include <sys/storage.h>
 #endif
@@ -140,6 +148,31 @@ StackBounds StackBounds::currentThreadStackBoundsInter
 StackBounds StackBounds::currentThreadStackBoundsInternal()
 {
     auto ret = newThreadStackBounds(pthread_self());
+#if OS(NETBSD)
+#if __NetBSD_Version__ < 1199000700
+    // Due to a bug in posix_spawn(3), AT_STACKBASE is wrong for the main thread.
+    // Use __ps_strings to find the top of the stack, and use that if the current
+    // stack falls in the computed range on affected NetBSD versions.
+    // https://gnats.netbsd.org/60653
+    if (__ps_strings) {
+WTF_ALLOW_UNSAFE_BUFFER_USAGE_BEGIN
+        char* origin = reinterpret_cast<char*>(__ps_strings) + sizeof(struct ps_strings);
+WTF_ALLOW_UNSAFE_BUFFER_USAGE_END
+        rlimit limit;
+        rlim_t size = 8 * MB;
+        if (!getrlimit(RLIMIT_STACK, &limit) && limit.rlim_cur != RLIM_INFINITY)
+            size = limit.rlim_cur;
+WTF_ALLOW_UNSAFE_BUFFER_USAGE_BEGIN
+        char* bound = origin - size;
+WTF_ALLOW_UNSAFE_BUFFER_USAGE_END
+        // Only the initial thread lives in that range; everybody else keeps
+        // the libpthread-reported bounds.
+        char* here = reinterpret_cast<char*>(&limit);
+        if (here > bound && here < origin)
+            return StackBounds { origin, bound };
+    }
+#endif
+#endif
 #if OS(LINUX)
     // on glibc, pthread_attr_getstack will generally return the limit size (minus a guard page)
     // for the main thread; this is however not necessarily always true on every libc - for example
