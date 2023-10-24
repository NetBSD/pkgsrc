$NetBSD: patch-System_Clock.hsc,v 1.2 2023/10/24 10:42:22 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- System/Clock.hsc.orig	2001-09-09 01:46:40.000000000 +0000
+++ System/Clock.hsc
@@ -149,8 +149,8 @@ type ClockId = CClockId
 type ClockId = #{type clockid_t}
 #endif
 
-foreign import ccall unsafe clock_gettime :: ClockId -> Ptr TimeSpec -> IO CInt
-foreign import ccall unsafe clock_getres  :: ClockId -> Ptr TimeSpec -> IO CInt
+foreign import capi unsafe "time.h clock_gettime" clock_gettime :: ClockId -> Ptr TimeSpec -> IO CInt
+foreign import capi unsafe "time.h clock_getres"  clock_getres  :: ClockId -> Ptr TimeSpec -> IO CInt
 
 foreign import capi unsafe "time.h value CLOCK_MONOTONIC" clock_MONOTONIC :: ClockId
 foreign import capi unsafe "time.h value CLOCK_REALTIME" clock_REALTIME :: ClockId
