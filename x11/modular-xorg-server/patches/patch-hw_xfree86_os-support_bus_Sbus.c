$NetBSD: patch-hw_xfree86_os-support_bus_Sbus.c,v 1.5 2022/07/15 20:39:49 wiz Exp $

Merge most of netbsdSbus.c from xsrc, but leave the Solaris support in place.

--- hw/xfree86/os-support/bus/Sbus.c.orig	2022-07-12 13:27:57.000000000 +0000
+++ hw/xfree86/os-support/bus/Sbus.c
@@ -34,6 +34,9 @@
 #ifdef __sun
 #include <sys/utsname.h>
 #endif
+#if defined(__NetBSD__) && defined(__sparc__)
+#include <dev/ofw/openfirmio.h>
+#endif
 #include "xf86.h"
 #include "xf86Priv.h"
 #include "xf86_OSlib.h"
@@ -50,7 +53,9 @@ static int promP1275 = -1;
 
 #define MAX_PROP	128
 #define MAX_VAL		(4096-128-4)
+#ifdef __sun
 static struct openpromio *promOpio;
+#endif
 
 sbusDevicePtr *xf86SbusInfo = NULL;
 
@@ -68,15 +73,27 @@ struct sbus_devtable sbusDeviceTable[] =
     {SBUS_DEVICE_GT, FBTYPE_SUNGT, "gt", NULL, "Sun Graphics Tower"},
     {SBUS_DEVICE_MGX, -1, "mgx", NULL, "Quantum 3D MGXplus"},
     {SBUS_DEVICE_LEO, FBTYPE_SUNLEO, "leo", "sunleo", "Sun ZX or Turbo ZX"},
-    {SBUS_DEVICE_TCX, FBTYPE_TCXCOLOR, "tcx", "suntcx", "Sun TCX"},
+    {SBUS_DEVICE_TCX, FBTYPE_TCXCOLOR, "tcx", "suntcx", "Sun TCX or S24"},
     {SBUS_DEVICE_FFB, FBTYPE_CREATOR, "ffb", "sunffb", "Sun FFB"},
     {SBUS_DEVICE_FFB, FBTYPE_CREATOR, "afb", "sunffb", "Sun Elite3D"},
+#ifdef FBTYPE_P9100
+    {SBUS_DEVICE_P9100, FBTYPE_P9100, "pnozz", "pnozz", "Weitek P9100"},
+#endif /* FBTYPE_P9100 */
+#ifdef FBTYPE_AG10E
+    {SBUS_DEVICE_AG10E, FBTYPE_AG10E, "ag10e", "ag10e", "Fujitsu AG-10e"},
+#endif /* FBTYPE_AG10E */
     {0, 0, NULL}
 };
 
+#ifndef __sun
+static struct ofiocdesc ofio;
+static char of_buf[256];
+#endif
+
 int
 promGetSibling(int node)
 {
+#ifdef __sun
     promOpio->oprom_size = sizeof(int);
 
     if (node == -1)
@@ -86,11 +103,20 @@ promGetSibling(int node)
         return 0;
     promCurrentNode = *(int *) promOpio->oprom_array;
     return *(int *) promOpio->oprom_array;
+#else
+    if (node == -1)
+        return 0;
+    if (ioctl(promFd, OFIOCGETNEXT, &node) < 0)
+        return 0;
+    promCurrentNode = node;
+    return node;
+#endif
 }
 
 int
 promGetChild(int node)
 {
+#ifdef __sun
     promOpio->oprom_size = sizeof(int);
 
     if (!node || node == -1)
@@ -100,26 +126,52 @@ promGetChild(int node)
         return 0;
     promCurrentNode = *(int *) promOpio->oprom_array;
     return *(int *) promOpio->oprom_array;
+#else
+    if (!node || node == -1)
+        return 0;
+    if (ioctl(promFd, OFIOCGETCHILD, &node) < 0)
+        return 0;
+    promCurrentNode = node;
+    return node;
+#endif
 }
 
 char *
 promGetProperty(const char *prop, int *lenp)
 {
+#ifdef __sun
     promOpio->oprom_size = MAX_VAL;
 
     strcpy(promOpio->oprom_array, prop);
     if (ioctl(promFd, OPROMGETPROP, promOpio) < 0)
         return 0;
+
     if (lenp)
         *lenp = promOpio->oprom_size;
     return promOpio->oprom_array;
+#else
+    ofio.of_nodeid = promCurrentNode;
+    ofio.of_name = (char *)prop;
+    ofio.of_namelen = strlen(prop);
+    ofio.of_buf = of_buf;
+    ofio.of_buflen = sizeof(of_buf);
+
+    if (ioctl(promFd, OFIOCGET, &ofio) < 0)
+        return 0;
+
+    of_buf[ofio.of_buflen] = '\0';
+
+    if (lenp)
+        *lenp = ofio.of_buflen;
+    return of_buf;
+#endif
 }
 
 int
 promGetBool(const char *prop)
 {
+#ifdef __sun
     promOpio->oprom_size = 0;
-
     *(int *) promOpio->oprom_array = 0;
     for (;;) {
         promOpio->oprom_size = MAX_PROP;
@@ -130,6 +182,19 @@ promGetBool(const char *prop)
         if (!strcmp(promOpio->oprom_array, prop))
             return 1;
     }
+#else
+    ofio.of_nodeid = promCurrentNode;
+    ofio.of_name = (char *)prop;
+    ofio.of_namelen = strlen(prop);
+    ofio.of_buf = of_buf;
+    ofio.of_buflen = sizeof(of_buf);
+
+    if (ioctl(promFd, OFIOCGET, &ofio) < 0)
+        return 0;
+    if (ofio.of_buflen < 0)
+        return 0;
+    return 1;
+#endif
 }
 
 #define PROM_NODE_SIBLING 0x01
@@ -180,7 +245,7 @@ promIsP1275(void)
         promP1275 = TRUE;
     else
         promP1275 = FALSE;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     promP1275 = TRUE;
 #else
 #error Missing promIsP1275() function for this OS
@@ -198,8 +263,10 @@ sparcPromClose(void)
         close(promFd);
         promFd = -1;
     }
+#ifdef __sun
     free(promOpio);
     promOpio = NULL;
+#endif
     promOpenCount = 0;
 }
 
@@ -213,11 +280,13 @@ sparcPromInit(void)
     promFd = open("/dev/openprom", O_RDONLY, 0);
     if (promFd == -1)
         return -1;
+#ifdef __sun
     promOpio = (struct openpromio *) malloc(4096);
     if (!promOpio) {
         sparcPromClose();
         return -1;
     }
+#endif
     promRootNode = promGetSibling(0);
     if (!promRootNode) {
         sparcPromClose();
@@ -399,9 +468,9 @@ sparcPromAssignNodes(void)
          * were the types of the cards missed. */
         char buffer[64];
         int fbNum, devId;
-        static struct {
-            int devId;
-            char *prefix;
+        static const struct {
+            const int devId;
+            const char *prefix;
         } procFbPrefixes[] = {
             {SBUS_DEVICE_BW2, "BWtwo"},
             {SBUS_DEVICE_CG14, "CGfourteen"},
