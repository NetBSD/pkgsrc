$NetBSD: patch-smblib.inc.c,v 1.1.1.1 2008/10/17 19:23:25 sborrill Exp $
--- smbval/smblib.inc.c.orig	2004-02-19 15:24:46.000000000 +0000
+++ smbval/smblib.inc.c	2008-10-17 17:50:39.000000000 +0100
@@ -22,8 +22,8 @@
 #include <stdio.h>
 #include <malloc.h>
 
-static int SMBlib_errno;
-static int SMBlib_SMB_Error;
+int SMBlib_errno;
+int SMBlib_SMB_Error;
 #define SMBLIB_ERRNO
 #define uchar unsigned char
 #include "smblib-priv.h"
@@ -33,7 +33,7 @@
 
 #include <signal.h>
 
-static SMB_State_Types SMBlib_State;
+SMB_State_Types SMBlib_State;
 
 /* Initialize the SMBlib package     */
 static int 
