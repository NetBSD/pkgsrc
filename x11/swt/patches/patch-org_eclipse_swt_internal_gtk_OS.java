$NetBSD: patch-org_eclipse_swt_internal_gtk_OS.java,v 1.1 2023/10/11 13:29:17 bouyer Exp $

--- org/eclipse/swt/internal/gtk/OS.java.orig	2021-09-06 01:22:24 UTC
+++ org/eclipse/swt/internal/gtk/OS.java
@@ -65,8 +65,8 @@ public class OS extends C {
 
 		/* Initialize the OS flags and locale constants */
 		String osName = System.getProperty ("os.name");
-		boolean isLinux = false, isWin32 = false;
-		if (osName.equals ("Linux")) isLinux = true;
+		boolean isLinux = osName.equals ("Linux") || osName.equals ("NetBSD");
+		boolean isWin32 = false;
 		if (osName.startsWith("Windows")) isWin32 = true;
 		IsLinux = isLinux;  IsWin32 = isWin32;
 
