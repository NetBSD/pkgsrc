$NetBSD: patch-Graphics_X11_Xlib_Event.hsc,v 1.1 2021/04/24 19:02:54 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- Graphics/X11/Xlib/Event.hsc.orig	2021-04-24 18:55:37.777127588 +0000
+++ Graphics/X11/Xlib/Event.hsc
@@ -1,4 +1,5 @@
 {-# LANGUAGE DeriveDataTypeable #-}
+{-# LANGUAGE CApiFFI #-}
 -----------------------------------------------------------------------------
 -- |
 -- Module      :  Graphics.X11.Xlib.Event
@@ -418,7 +419,7 @@ newtype FdSet = FdSet (Ptr FdSet)
 foreign import ccall unsafe "HsXlib.h" fdZero :: Ptr FdSet -> IO ()
 foreign import ccall unsafe "HsXlib.h" fdSet :: CInt -> Ptr FdSet -> IO ()
 
-foreign import ccall unsafe "HsXlib.h" select ::
+foreign import capi unsafe "sys/select.h select" select ::
         CInt -> Ptr FdSet -> Ptr FdSet -> Ptr FdSet -> Ptr TimeVal -> IO CInt
 
 -- | This function is somewhat compatible with Win32's @TimeGetTime()@
@@ -449,7 +450,7 @@ newtype TimeZone = TimeZone (Ptr TimeZon
         deriving (Eq, Ord, Show)
 #endif
 
-foreign import ccall unsafe "HsXlib.h"
+foreign import capi unsafe "sys/time.h gettimeofday"
         gettimeofday :: Ptr TimeVal -> Ptr TimeZone -> IO ()
 
 -- | interface to the X11 library function @XFlush()@.
