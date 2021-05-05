$NetBSD: patch-Data_UnixTime_Sys.hsc,v 1.1 2021/05/05 12:22:59 pho Exp $

Suppress a linker warning about compatibility symbol by using "capi"
instead of "ccall".

--- Data/UnixTime/Sys.hsc.orig	2021-05-05 12:20:27.485637043 +0000
+++ Data/UnixTime/Sys.hsc
@@ -1,4 +1,5 @@
 {-# LANGUAGE ForeignFunctionInterface #-}
+{-# LANGUAGE CApiFFI #-}
 
 module Data.UnixTime.Sys (getUnixTime) where
 
@@ -17,7 +18,7 @@ import Foreign.Storable
 type CTimeVal = ()
 type CTimeZone = ()
 
-foreign import ccall unsafe "gettimeofday"
+foreign import capi unsafe "sys/time.h gettimeofday"
     c_gettimeofday :: Ptr CTimeVal -> Ptr CTimeZone -> IO CInt
 
 -- |
