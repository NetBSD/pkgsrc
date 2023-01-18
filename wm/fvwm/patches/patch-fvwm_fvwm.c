$NetBSD: patch-fvwm_fvwm.c,v 1.1 2023/01/18 07:43:16 vins Exp $

Remove compile time __DATE__ and __TIME__ variables from the source.

It looks like upstream rejected the request for inclusion in
https://github.com/fvwmorg/fvwm/issues/67 and focuses on fvwm3 fixes.
This patch has been taken from a similar (but not applying as-is) patch
by robert@openbsd for OpenBSD's Xenocara tree FVWM version.

--- fvwm/fvwm.c~
+++ fvwm/fvwm.c
@@ -1286,8 +1286,8 @@ static void setVersionInfo(void)
 	int support_len;
 
 	/* Set version information string */
-	sprintf(version_str, "fvwm %s%s compiled on %s at %s",
-		VERSION, VERSIONINFO, __DATE__, __TIME__);
+	sprintf(version_str, "fvwm %s%s\n",
+		VERSION, VERSIONINFO);
 	Fvwm_VersionInfo = safestrdup(version_str);
 
 	sprintf(license_str,
