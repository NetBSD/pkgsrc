$NetBSD: patch-Source_WebCore_page_csp_ContentSecurityPolicy.cpp,v 1.1 2024/08/17 10:58:39 tnn Exp $

Work around GCC 14 issue:

/usr/include/c++/14/bits/stl_pair.h:922:38:   required from 'struct std::pair<WebCore::ContentSecurityPolicyHashAlgorithm, WTF::Vector<unsigned char> >'
  922 |                                        is_copy_assignable<_T2>>::value,
      |                                                                  ^~~~~
/tnn/pkgsrc-obj/x11/qt5-qtwebkit/work/qtwebkit-5.212.0-alpha4/Source/WebCore/page/csp/ContentSecurityPolicy.cpp:235:56:   required from here
  235 |             if ((policy.get()->*allowed)(std::make_pair(algorithm, digest)))
      |                                          ~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~
/usr/include/c++/14/type_traits:1237:52: error: non-constant condition for static assertion
 1237 |       static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),

--- Source/WebCore/page/csp/ContentSecurityPolicy.cpp.orig	2024-08-17 11:46:46.999690372 +0000
+++ Source/WebCore/page/csp/ContentSecurityPolicy.cpp
@@ -231,8 +231,9 @@ bool isAllowedByAllWithHashFromContent(c
         auto cryptoDigest = CryptoDigest::create(toCryptoDigestAlgorithm(algorithm));
         cryptoDigest->addBytes(contentCString.data(), contentCString.length());
         Vector<uint8_t> digest = cryptoDigest->computeHash();
+	auto p = std::make_pair(algorithm, digest);
         for (auto& policy : policies) {
-            if ((policy.get()->*allowed)(std::make_pair(algorithm, digest)))
+            if ((policy.get()->*allowed)(p))
                 return true;
         }
     }
