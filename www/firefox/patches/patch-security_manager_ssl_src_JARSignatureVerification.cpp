$NetBSD: patch-security_manager_ssl_src_JARSignatureVerification.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- security/manager/ssl/src/JARSignatureVerification.cpp.orig	2014-01-28 04:04:01.000000000 +0000
+++ security/manager/ssl/src/JARSignatureVerification.cpp
@@ -596,9 +596,9 @@ OpenSignedJARFile(nsIFile * aJarFile,
   }
 
   // Verify that the signature file is a valid signature of the SF file
-  if (!SEC_PKCS7VerifyDetachedSignatureAtTime(p7_info, certUsageObjectSigner,
-                                              &sfCalculatedDigest.get(),
-                                              HASH_AlgSHA1, false, PR_Now())) {
+  if (!SEC_PKCS7VerifyDetachedSignature(p7_info, certUsageObjectSigner,
+                                        &sfCalculatedDigest.get(), HASH_AlgSHA1,
+                                        false)) {
     PRErrorCode error = PR_GetError();
     const char * errorName = PR_ErrorToName(error);
     PR_LOG(gPIPNSSLog, PR_LOG_DEBUG, ("Failed to verify detached signature: %s",
