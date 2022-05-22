$NetBSD: patch-hw_xfree86_os-support_solaris_sun__init.c,v 1.1 2022/05/22 21:29:58 dholland Exp $

Fix sparc Solaris build.

--- hw/xfree86/os-support/solaris/sun_init.c~	2021-12-15 19:01:24.000000000 +0000
+++ hw/xfree86/os-support/solaris/sun_init.c
@@ -61,6 +61,7 @@ static char consoleDev[PATH_MAX] = "/dev
    Used by hw/xfree86/common/xf86AutoConfig.c for VIS_GETIDENTIFIER */
 _X_HIDDEN char xf86SolarisFbDev[PATH_MAX] = "/dev/fb";
 
+#ifdef HAS_USL_VTS
 static void
 switch_to(int vt, const char *from)
 {
@@ -76,6 +77,7 @@ switch_to(int vt, const char *from)
         xf86Msg(X_WARNING, "%s: VT_WAITACTIVE failed: %s\n",
                 from, strerror(errno));
 }
+#endif
 
 void
 xf86OpenConsole(void)
