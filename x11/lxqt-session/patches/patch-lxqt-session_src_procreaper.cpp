$NetBSD: patch-lxqt-session_src_procreaper.cpp,v 1.1 2021/11/19 14:17:44 gutteridge Exp $

Add NetBSD support, and make this at least possibly compile elsewhere,
as POSIX kill() is expected universally.
https://github.com/lxqt/lxqt-session/pull/403

--- lxqt-session/src/procreaper.cpp.orig	2021-11-05 10:14:38.000000000 +0000
+++ lxqt-session/src/procreaper.cpp
@@ -34,11 +34,15 @@
 #include <sys/procctl.h>
 #include <libutil.h>
 #include <sys/user.h>
-#include <signal.h>
+#elif defined(Q_OS_NETBSD)
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 #include <unistd.h>
 #include <cstring>
 #include <cerrno>
+#include <signal.h>
 #include <sys/wait.h>
 
 ProcReaper::ProcReaper()
@@ -128,6 +132,31 @@ void ProcReaper::stop(const std::set<int
         }
         free(proc_info);
     }
+#elif defined(Q_OS_NETBSD)
+    int cnt = 0;
+    kvm_t * kd;
+    char buf[_POSIX2_LINE_MAX];
+
+    if ((kd = kvm_openfiles(nullptr, nullptr, nullptr, KVM_NO_FILES, buf)))
+    {
+        if (kinfo_proc2 *proc_info = kvm_getproc2(kd, KERN_PROC_ALL, 0, sizeof(struct kinfo_proc2), &cnt))
+        {
+            for (int i = 0; i < cnt; ++i)
+            {
+                if (proc_info[i].p_ppid == my_pid)
+                {
+                    children.push_back(proc_info[i].p_pid);
+                }
+            }
+            free(proc_info);
+        }
+        else
+            qCWarning(SESSION) << "Unable to access process information: " << kvm_geterr(kd);
+
+        free(kd);
+    }
+    else
+        qCWarning(SESSION) << "Unable to access kernel virtual memory: " << buf;
 #endif
     for (auto const & child : children)
     {
