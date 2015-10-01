$NetBSD: patch-hw_xquartz_GL_indirect.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- hw/xquartz/GL/indirect.c.orig	2014-02-05 03:08:57.000000000 +0000
+++ hw/xquartz/GL/indirect.c
@@ -52,6 +52,7 @@
 
 #include "visualConfigs.h"
 #include "dri.h"
+#include "extension_string.h"
 
 #include "darwin.h"
 #define GLAQUA_DEBUG_MSG(msg, args ...) ASL_LOG(ASL_LEVEL_DEBUG, "GLXAqua", \
@@ -111,6 +112,10 @@ typedef struct __GLXAquaDrawable __GLXAq
  */
 struct __GLXAquaScreen {
     __GLXscreen base;
+
+    /* Supported GLX extensions */
+    unsigned char glx_enable_bits[__GLX_EXT_BYTES];
+
     int index;
     int num_vis;
 };
@@ -541,13 +546,33 @@ __glXAquaScreenProbe(ScreenPtr pScreen)
 
     screen->base.GLXmajor = 1;
     screen->base.GLXminor = 4;
-    screen->base.GLXextensions = strdup("GLX_SGIX_fbconfig "
-                                        "GLX_SGIS_multisample "
-                                        "GLX_ARB_multisample "
-                                        "GLX_EXT_visual_info "
-                                        "GLX_EXT_import_context ");
 
-    /*We may be able to add more GLXextensions at a later time. */
+    memset(screen->glx_enable_bits, 0, __GLX_EXT_BYTES);
+
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_EXT_visual_info");
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_EXT_visual_rating");
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_EXT_import_context");
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_OML_swap_method");
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_SGIX_fbconfig");
+
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_SGIS_multisample");
+    __glXEnableExtension(screen->glx_enable_bits, "GLX_ARB_multisample");
+
+    //__glXEnableExtension(screen->glx_enable_bits, "GLX_ARB_create_context");
+    //__glXEnableExtension(screen->glx_enable_bits, "GLX_ARB_create_context_profile");
+
+    // Generate the GLX extensions string (overrides that set by __glXScreenInit())
+    {
+        unsigned int buffer_size =
+            __glXGetExtensionString(screen->glx_enable_bits, NULL);
+        if (buffer_size > 0) {
+            free(screen->base.GLXextensions);
+
+            screen->base.GLXextensions = xnfalloc(buffer_size);
+            __glXGetExtensionString(screen->glx_enable_bits,
+                                    screen->base.GLXextensions);
+        }
+    }
 
     return &screen->base;
 }
