$NetBSD: patch-os.c,v 1.1 2023/10/11 13:29:17 bouyer Exp $

--- os.c.orig	2021-09-06 01:22:24 UTC
+++ os.c
@@ -15180,11 +15180,16 @@ JNIEXPORT jlong JNICALL OS_NATIVE(realpath)
 	jlong rc = 0;
 	OS_NATIVE_ENTER(env, that, realpath_FUNC);
 	if (arg0) if ((lparg0 = (*env)->GetByteArrayElements(env, arg0, NULL)) == NULL) goto fail;
-	if (arg1) if ((lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL)) == NULL) goto fail;
+	if (arg1) {
+	    if ((lparg1 = (*env)->GetByteArrayElements(env, arg1, NULL)) == NULL) goto fail;
+	} else
+	    lparg1 = malloc(PATH_MAX);
 	rc = (jlong)realpath((const char *)lparg0, (char *)lparg1);
 fail:
 	if (arg1 && lparg1) (*env)->ReleaseByteArrayElements(env, arg1, lparg1, 0);
 	if (arg0 && lparg0) (*env)->ReleaseByteArrayElements(env, arg0, lparg0, 0);
+	if (!arg1 && lparg1 && rc == 0)
+	    free(lparg1);
 	OS_NATIVE_EXIT(env, that, realpath_FUNC);
 	return rc;
 }
