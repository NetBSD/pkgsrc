$NetBSD: patch-src_corelib_io_qlockfile__unix.cpp,v 1.2 2016/12/04 21:46:54 marino Exp $

Add support for NetBSD and OpenBSD.
Enable fallback to unsupported for DragonFly

--- src/corelib/io/qlockfile_unix.cpp.orig	2015-10-13 04:35:31 UTC
+++ src/corelib/io/qlockfile_unix.cpp
@@ -54,6 +54,10 @@
 #elif defined(Q_OS_LINUX)
 #   include <unistd.h>
 #   include <cstdio>
+#elif defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+#   include <kvm.h>
+#   include <sys/param.h>
+#   include <sys/sysctl.h>
 #elif defined(Q_OS_BSD4) && !defined(Q_OS_IOS)
 #   include <sys/user.h>
 # if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
@@ -239,7 +243,20 @@ QString QLockFilePrivate::processNameByP
     }
     buf[len] = 0;
     return QFileInfo(QFile::decodeName(buf)).fileName();
-#elif defined(Q_OS_BSD4) && !defined(Q_OS_IOS)
+#elif defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+    kvm_t *kd = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, NULL);
+    int cnt;
+    QString name;
+    struct kinfo_proc2 *proc = kvm_getproc2(kd, KERN_PROC_PID, (int)pid, sizeof(struct kinfo_proc2), &cnt);
+    if (!proc) {
+        name = QString();
+    }
+    else {
+        name = QFile::decodeName(proc->p_comm);
+    }
+    kvm_close(kd);
+    return name;
+#elif defined(Q_OS_BSD4) && !defined(Q_OS_IOS) && !defined(__DragonFly__)
 # if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
     int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid };
     size_t len = 0;
