$NetBSD: patch-netwerk_base_nsStandardURL.cpp,v 1.1 2017/08/10 14:46:15 ryoon Exp $

--- netwerk/base/nsStandardURL.cpp.orig	2017-07-31 16:20:51.000000000 +0000
+++ netwerk/base/nsStandardURL.cpp
@@ -858,6 +858,7 @@ nsStandardURL::BuildNormalizedSpec(const
         if (!SegmentIs(spec, mScheme, "resource") &&
             !SegmentIs(spec, mScheme, "chrome")) {
             nsAutoCString ipString;
+#ifdef MOZ_RUST
             if (encHost.Length() > 0 &&
                 encHost.First() == '[' && encHost.Last() == ']' &&
                 ValidIPv6orHostname(encHost.get(), encHost.Length())) {
@@ -866,7 +867,9 @@ nsStandardURL::BuildNormalizedSpec(const
                     return rv;
                 }
                 encHost = ipString;
-            } else if (NS_SUCCEEDED(NormalizeIPv4(encHost, ipString))) {
+            } else
+#endif
+            if (NS_SUCCEEDED(NormalizeIPv4(encHost, ipString))) {
                 encHost = ipString;
             }
         }
@@ -2112,6 +2115,7 @@ nsStandardURL::SetHost(const nsACString 
 
     if (!SegmentIs(mScheme, "resource") && !SegmentIs(mScheme, "chrome")) {
         nsAutoCString ipString;
+#ifdef MOZ_RUST
         if (hostBuf.Length() > 0 &&
             hostBuf.First() == '[' && hostBuf.Last() == ']' &&
             ValidIPv6orHostname(hostBuf.get(), hostBuf.Length())) {
@@ -2120,7 +2124,9 @@ nsStandardURL::SetHost(const nsACString 
                 return rv;
             }
             hostBuf = ipString;
-        } else if (NS_SUCCEEDED(NormalizeIPv4(hostBuf, ipString))) {
+        } else
+#endif
+        if (NS_SUCCEEDED(NormalizeIPv4(hostBuf, ipString))) {
           hostBuf = ipString;
         }
     }
