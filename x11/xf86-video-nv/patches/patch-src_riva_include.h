$NetBSD: patch-src_riva_include.h,v 1.1 2015/04/02 22:16:47 tnn Exp $

From fc78fe98222b0204b8a2872a529763d6fe5048da Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:49 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/riva_include.h b/src/riva_include.h
index f2c5302..c7aeef7 100644
--- src/riva_include.h.orig	2012-07-17 06:48:45.000000000 +0000
+++ src/riva_include.h
@@ -22,9 +22,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 #include "micmap.h"
 
 #include "xf86DDC.h"
