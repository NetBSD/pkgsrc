$NetBSD: patch-Source_WebCore_crypto_algorithms_CryptoAlgorithmAES__GCM.cpp,v 1.1 2020/07/28 14:24:03 leot Exp $

Define non-stardard __WORDSIZE.

--- Source/WebCore/crypto/algorithms/CryptoAlgorithmAES_GCM.cpp.orig	2020-02-04 10:24:07.000000000 +0000
+++ Source/WebCore/crypto/algorithms/CryptoAlgorithmAES_GCM.cpp
@@ -26,6 +26,10 @@
 #include "config.h"
 #include "CryptoAlgorithmAES_GCM.h"
 
+#ifndef __WORDSIZE
+#define __WORDSIZE (__SIZEOF_LONG__ * 8)
+#endif
+
 #if ENABLE(WEB_CRYPTO)
 
 #include "CryptoAlgorithmAesGcmParams.h"
