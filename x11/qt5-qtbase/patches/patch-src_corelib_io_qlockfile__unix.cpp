$NetBSD: patch-src_corelib_io_qlockfile__unix.cpp,v 1.1 2015/10/26 19:03:59 adam Exp $

Add support for NetBSD and OpenBSD.

--- src/corelib/io/qlockfile_unix.cpp.orig	2015-10-25 12:40:42.000000000 +0000
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
@@ -239,6 +243,19 @@ QString QLockFilePrivate::processNameByP
     }
     buf[len] = 0;
     return QFileInfo(QFile::decodeName(buf)).fileName();
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
 #elif defined(Q_OS_BSD4) && !defined(Q_OS_IOS)
 # if defined(__GLIBC__) && defined(__FreeBSD_kernel__)
     int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid };
