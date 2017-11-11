$NetBSD: patch-buck_programs_timing.py,v 1.1 2017/11/11 21:30:21 tnn Exp $

buck: NetBSD support.

--- ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/programs/timing.py.orig	2017-09-21 14:10:58.000000000 +0000
+++ ../buck-buck-release-be2bf932342e5d67f58c9b26f5065c745d285d0d/programs/timing.py
@@ -83,3 +83,8 @@ elif platform.system() == 'FreeBSD':
     libc = ctypes.CDLL('libc.so.7', use_errno=True)
     clock_gettime = libc.clock_gettime
     set_posix_time_nanos(clock_gettime, CLOCK_MONOTONIC)
+elif platform.system() == 'NetBSD':
+    CLOCK_MONOTONIC = 3
+    libc = ctypes.CDLL('libc.so', use_errno=True)
+    clock_gettime = libc.clock_gettime
+    set_posix_time_nanos(clock_gettime, CLOCK_MONOTONIC)
