$NetBSD: patch-Data_Hourglass_Internal_Unix.hs,v 1.1 2021/04/23 10:16:07 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- Data/Hourglass/Internal/Unix.hs.orig	2021-04-23 10:12:09.501804974 +0000
+++ Data/Hourglass/Internal/Unix.hs
@@ -11,6 +11,7 @@
 -- Some obscure unix system might not support them.
 --
 {-# LANGUAGE ForeignFunctionInterface #-}
+{-# LANGUAGE CApiFFI #-}
 {-# LANGUAGE CPP #-}
 {-# LANGUAGE EmptyDataDecls #-}
 module Data.Hourglass.Internal.Unix
@@ -76,16 +77,16 @@ foreign import ccall unsafe "hourglass_c
     c_clock_get :: Ptr CLong -> IO ()
 
 #if (MIN_VERSION_base(4,5,0))
-foreign import ccall unsafe "gmtime_r"
+foreign import capi unsafe "time.h gmtime_r"
     c_gmtime_r :: Ptr CTime -> Ptr CTm -> IO (Ptr CTm)
 
-foreign import ccall unsafe "localtime_r"
+foreign import capi unsafe "time.h localtime_r"
     c_localtime_r :: Ptr CTime -> Ptr CTm -> IO (Ptr CTm)
 #else
-foreign import ccall unsafe "gmtime_r"
+foreign import capi unsafe "time.h gmtime_r"
     c_gmtime_r :: Ptr CLong -> Ptr CTm -> IO (Ptr CTm)
 
-foreign import ccall unsafe "localtime_r"
+foreign import capi unsafe "time.h localtime_r"
     c_localtime_r :: Ptr CLong -> Ptr CTm -> IO (Ptr CTm)
 #endif
 
