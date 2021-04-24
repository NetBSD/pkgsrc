$NetBSD: patch-System_Clock.hsc,v 1.1 2021/04/24 05:17:54 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- System/Clock.hsc.orig	2001-09-09 01:46:40.000000000 +0000
+++ System/Clock.hsc
@@ -2,6 +2,7 @@
 --   systems. This module is being developed according to IEEE Std
 --   1003.1-2008: <http://www.opengroup.org/onlinepubs/9699919799/>,
 --   <http://www.opengroup.org/onlinepubs/9699919799/functions/clock_getres.html#>
+{-# LANGUAGE CApiFFI #-}
 
 {-# OPTIONS_GHC -fno-warn-type-defaults #-}
 -- To allow importing Data.Int and Data.Word indiscriminately on all platforms,
@@ -129,8 +130,8 @@ foreign import ccall unsafe hs_clock_win
 foreign import ccall unsafe hs_clock_win32_getres_processtime :: Ptr TimeSpec -> IO ()
 foreign import ccall unsafe hs_clock_win32_getres_threadtime :: Ptr TimeSpec -> IO ()
 #else
-foreign import ccall unsafe clock_gettime :: #{type clockid_t} -> Ptr TimeSpec -> IO CInt
-foreign import ccall unsafe clock_getres  :: #{type clockid_t} -> Ptr TimeSpec -> IO CInt
+foreign import capi unsafe "time.h clock_gettime" clock_gettime :: #{type clockid_t} -> Ptr TimeSpec -> IO CInt
+foreign import capi unsafe "time.h clock_getres"  clock_getres  :: #{type clockid_t} -> Ptr TimeSpec -> IO CInt
 #endif
 
 #if !defined(_WIN32)
