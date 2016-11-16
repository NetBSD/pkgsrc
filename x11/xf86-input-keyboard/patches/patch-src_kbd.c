$NetBSD: patch-src_kbd.c,v 1.1 2016/11/16 22:53:22 wiz Exp $

157e0631b12d0aae4a5f38b81bee615a7eaf553f from upstream git.

--- src/kbd.c.orig	2013-10-28 00:44:15.000000000 +0000
+++ src/kbd.c
@@ -45,6 +45,10 @@
 #include "xkbstr.h"
 #include "xkbsrv.h"
 
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 23
+#define HAVE_THREADED_INPUT	1
+#endif
+
 #define CAPSFLAG	1
 #define NUMFLAG		2
 #define SCROLLFLAG	4
@@ -53,11 +57,7 @@
 /* Used to know when the first DEVICE_ON after a DEVICE_INIT is called */
 #define INITFLAG	(1U << 31)
 
-#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 12
-static InputInfoPtr KbdPreInit(InputDriverPtr drv, IDevPtr dev, int flags);
-#else
 static int KbdPreInit(InputDriverPtr drv, InputInfoPtr pInfo, int flags);
-#endif
 static int KbdProc(DeviceIntPtr device, int what);
 static void KbdCtrl(DeviceIntPtr device, KeybdCtrl *ctrl);
 static void KbdBell(int percent, DeviceIntPtr dev, pointer ctrl, int unused);
@@ -66,24 +66,6 @@ static void PostKbdEvent(InputInfoPtr pI
 static void InitKBD(InputInfoPtr pInfo, Bool init);
 static void UpdateLeds(InputInfoPtr pInfo);
 
-_X_EXPORT InputDriverRec KBD = {
-	1,
-	"kbd",
-	NULL,
-	KbdPreInit,
-	NULL,
-	NULL
-};
-
-_X_EXPORT InputDriverRec KEYBOARD = {
-	1,
-	"keyboard",
-	NULL,
-	KbdPreInit,
-	NULL,
-	NULL
-};
-
 static const char *kbdDefaults[] = {
 #ifdef __NetBSD__
 #ifdef DEFAULT_TO_WSKBD
@@ -106,43 +88,52 @@ static char *xkb_layout;
 static char *xkb_variant;
 static char *xkb_options;
 
-#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 12
-static int
-NewKbdPreInit(InputDriverPtr drv, InputInfoPtr pInfo, int flags);
-
-static InputInfoPtr
-KbdPreInit(InputDriverPtr drv, IDevPtr dev, int flags)
-{
-    InputInfoPtr pInfo;
+_X_EXPORT InputDriverRec KBD = {
+    1,
+    "kbd",
+    NULL,
+    KbdPreInit,
+    NULL,
+    NULL
+};
 
-    if (!(pInfo = xf86AllocateInput(drv, 0)))
-	return NULL;
+_X_EXPORT InputDriverRec KEYBOARD = {
+    1,
+    "keyboard",
+    NULL,
+    KbdPreInit,
+    NULL,
+    NULL
+};
 
-    pInfo->name = dev->identifier;
-    pInfo->flags = XI86_KEYBOARD_CAPABLE;
-    pInfo->conversion_proc = NULL;
-    pInfo->reverse_conversion_proc = NULL;
-    pInfo->private_flags = 0;
-    pInfo->always_core_feedback = NULL;
-    pInfo->conf_idev = dev;
-    pInfo->close_proc = NULL;
-
-    if (NewKbdPreInit(drv, pInfo, flags) == Success)
-    {
-        pInfo->flags |= XI86_CONFIGURED;
-        return pInfo;
-    }
+static XF86ModuleVersionInfo xf86KbdVersionRec = {
+    "kbd",
+    MODULEVENDORSTRING,
+    MODINFOSTRING1,
+    MODINFOSTRING2,
+    XORG_VERSION_CURRENT,
+    PACKAGE_VERSION_MAJOR, PACKAGE_VERSION_MINOR, PACKAGE_VERSION_PATCHLEVEL,
+    ABI_CLASS_XINPUT,
+    ABI_XINPUT_VERSION,
+    MOD_CLASS_XINPUT,
+    {0, 0, 0, 0}
+};
 
-    xf86DeleteInput(pInfo, 0);
-    return NULL;
+static pointer
+xf86KbdPlug(pointer module, pointer options, int *errmaj, int *errmin)
+{
+    xf86AddInputDriver(&KBD, module, 0);
+    return module;
 }
 
-static int
-NewKbdPreInit(InputDriverPtr drv, InputInfoPtr pInfo, int flags)
-#else
+_X_EXPORT XF86ModuleData kbdModuleData = {
+    &xf86KbdVersionRec,
+    xf86KbdPlug,
+    NULL
+};
+
 static int
 KbdPreInit(InputDriverPtr drv, InputInfoPtr pInfo, int flags)
-#endif
 {
     KbdDevPtr pKbd;
     char *s;
@@ -163,11 +154,7 @@ KbdPreInit(InputDriverPtr drv, InputInfo
     pInfo->dev = NULL;
 
     defaults = kbdDefaults;
-    xf86CollectInputOptions(pInfo, defaults
-#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 12
-            , NULL
-#endif
-            );
+    xf86CollectInputOptions(pInfo, defaults);
     xf86ProcessCommonOptions(pInfo, pInfo->options); 
 
     if (!(pKbd = calloc(sizeof(KbdDevRec), 1))) {
@@ -309,6 +296,7 @@ KbdProc(DeviceIntPtr device, int what)
 
   InputInfoPtr pInfo = device->public.devicePrivate;
   KbdDevPtr pKbd = (KbdDevPtr) pInfo->private;
+  XkbRMLVOSet rmlvo;
   KeySymsRec           keySyms;
   CARD8                modMap[MAP_LENGTH];
   int                  ret;
@@ -322,23 +310,19 @@ KbdProc(DeviceIntPtr device, int what)
          pKbd->KbdGetMapping(pInfo, &keySyms, modMap);
 
          device->public.on = FALSE;
-#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 5
-         {
-             XkbRMLVOSet rmlvo;
-             rmlvo.rules = xkb_rules;
-             rmlvo.model = xkb_model;
-             rmlvo.layout = xkb_layout;
-             rmlvo.variant = xkb_variant;
-             rmlvo.options = xkb_options;
+         rmlvo.rules = xkb_rules;
+         rmlvo.model = xkb_model;
+         rmlvo.layout = xkb_layout;
+         rmlvo.variant = xkb_variant;
+         rmlvo.options = xkb_options;
 
-             if (!InitKeyboardDeviceStruct(device, &rmlvo, KbdBell, KbdCtrl))
-             {
-                 xf86Msg(X_ERROR, "%s: Keyboard initialization failed. This "
-                         "could be a missing or incorrect setup of "
-                         "xkeyboard-config.\n", device->name);
+         if (!InitKeyboardDeviceStruct(device, &rmlvo, KbdBell, KbdCtrl))
+         {
+             xf86Msg(X_ERROR, "%s: Keyboard initialization failed. This "
+                     "could be a missing or incorrect setup of "
+                     "xkeyboard-config.\n", device->name);
 
-                 return BadValue;
-             }
+             return BadValue;
          }
 # ifdef XI_PROP_DEVICE_NODE
          {
@@ -355,17 +339,6 @@ KbdProc(DeviceIntPtr device, int what)
              }
          }
 # endif /* XI_PROP_DEVICE_NODE */
-#else
-         {
-             XkbComponentNamesRec xkbnames;
-             memset(&xkbnames, 0, sizeof(xkbnames));
-             XkbSetRulesDflts(xkb_rules, xkb_model, xkb_layout,
-                              xkb_variant, xkb_options);
-             XkbInitKeyboardDeviceStruct(device, &xkbnames, &keySyms,
-                                         modMap, KbdBell,
-                                         (KbdCtrlProcPtr)KbdCtrl);
-         }
-#endif /* XINPUT ABI 5*/
          InitKBD(pInfo, TRUE);
          break;
   case DEVICE_ON:
@@ -383,7 +356,11 @@ KbdProc(DeviceIntPtr device, int what)
      */
     if (pInfo->fd >= 0) {
 	xf86FlushInput(pInfo->fd);
+#if HAVE_THREADED_INPUT
+	xf86AddEnabledDevice(pInfo);
+#else
 	AddEnabledDevice(pInfo->fd);
+#endif
     }
 
     device->public.on = TRUE;
@@ -396,8 +373,13 @@ KbdProc(DeviceIntPtr device, int what)
     /*
      * Restore original keyboard directness and translation.
      */
-    if (pInfo->fd != -1)
+    if (pInfo->fd != -1) {
+#if HAVE_THREADED_INPUT
+      xf86RemoveEnabledDevice(pInfo);
+#else
       RemoveEnabledDevice(pInfo->fd);
+#endif
+    }
     pKbd->KbdOff(pInfo, what);
     device->public.on = FALSE;
     break;
@@ -451,40 +433,3 @@ PostKbdEvent(InputInfoPtr pInfo, unsigne
 
   xf86PostKeyboardEvent(device, scanCode + MIN_KEYCODE, down);
 }
-
-static void
-xf86KbdUnplug(pointer	p)
-{
-}
-
-static pointer
-xf86KbdPlug(pointer	module,
-	    pointer	options,
-	    int		*errmaj,
-	    int		*errmin)
-{
-    xf86AddInputDriver(&KBD, module, 0);
-
-    return module;
-}
-
-static XF86ModuleVersionInfo xf86KbdVersionRec =
-{
-    "kbd",
-    MODULEVENDORSTRING,
-    MODINFOSTRING1,
-    MODINFOSTRING2,
-    XORG_VERSION_CURRENT,
-    PACKAGE_VERSION_MAJOR, PACKAGE_VERSION_MINOR, PACKAGE_VERSION_PATCHLEVEL,
-    ABI_CLASS_XINPUT,
-    ABI_XINPUT_VERSION,
-    MOD_CLASS_XINPUT,
-    {0, 0, 0, 0}		/* signature, to be patched into the file by */
-				/* a tool */
-};
-
-_X_EXPORT XF86ModuleData kbdModuleData = {
-    &xf86KbdVersionRec,
-    xf86KbdPlug,
-    xf86KbdUnplug
-};
