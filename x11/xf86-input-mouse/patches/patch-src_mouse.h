$NetBSD: patch-src_mouse.h,v 1.1 2012/05/06 20:51:24 wiz Exp $

Changes from NetBSD xsrc/external/mit/xorg-server/dist/\
hw/xfree86/os-support/xf86OSmouse.h

----------------------------
revision 1.2
date: 2009/02/02 03:06:37;  author: christos;  state: Exp;  lines: +4 -0
add a SetupMouse proc to condition the fd. Convert NetBSD's SetupAuto to
SetupMouse.
----------------------------

--- src/mouse.h.orig	2012-05-05 07:22:19.910022000 +0000
+++ src/mouse.h
@@ -91,6 +91,7 @@ typedef Bool (*BuiltinPreInitProc)(Input
 				   int flags);
 typedef const char *(*DefaultProtocolProc)(void);
 typedef const char *(*SetupAutoProc)(InputInfoPtr pInfo, int *protoPara);
+typedef Bool (*SetupMouseProc)(InputInfoPtr pInfo);
 typedef void (*SetResProc)(InputInfoPtr pInfo, const char* protocol, int rate,
 			   int res);
 typedef const char *(*FindDeviceProc)(InputInfoPtr pInfo, const char *protocol,
@@ -108,6 +109,7 @@ typedef struct {
 	BuiltinPreInitProc	PreInit;
 	DefaultProtocolProc	DefaultProtocol;
 	SetupAutoProc		SetupAuto;
+	SetupMouseProc		SetupMouse;
 	SetResProc		SetPS2Res;
 	SetResProc		SetBMRes;
 	SetResProc		SetMiscRes;
@@ -150,6 +152,8 @@ typedef struct {
  *
  * SetBMRes:	Set the resolution and sample rate for MSE_BM protocol types.
  *
+ * SetupMouse:	Called once after open to condition the file descriptor.
+ *
  * SetMiscRes:	Set the resolution and sample rate for MSE_MISC protocol types.
  *
  * FindDevice:	This function gets called when no Device has been specified
