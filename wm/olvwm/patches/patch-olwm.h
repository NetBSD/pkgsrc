$NetBSD: patch-olwm.h,v 1.1 2013/03/28 21:40:11 joerg Exp $

--- olwm.h.orig	2013-03-28 19:18:35.000000000 +0000
+++ olwm.h
@@ -107,7 +107,6 @@ extern struct _wingeneric *NoFocusWinInf
 extern struct _wingeneric *MakeNoFocus();
 extern void NoFocusTakeFocus();
 extern void NoFocusInit();
-extern int NoFocusEventBeep();
 
 /* client information and functions */
 extern struct _List *ActiveClientList;
@@ -147,8 +146,6 @@ extern int GFrameSetConfigFunc();
 extern void GFrameSetStack();
 extern void GFrameSetConfig();
 extern int GFrameEventButtonPress();
-extern int GFrameEventMotionNotify();
-extern int GFrameEventButtonRelease();
 extern int GFrameEventFocus();
 extern int GFrameEventEnterNotify();
 
@@ -187,7 +184,6 @@ extern void ColormapTransmogrify();
 extern Bool IsSelected();
 extern struct _client *EnumSelections();
 extern Time TimeFresh();
-extern int AddSelection();
 extern Bool RemoveSelection();
 extern Bool ToggleSelection();
 extern void ClearSelections();
