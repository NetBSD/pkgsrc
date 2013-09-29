$NetBSD: patch-shibsp_attribute_resolver_impl_ChainingAttributeExtractor.cpp,v 1.1 2013/09/29 10:19:47 joerg Exp $

--- shibsp/attribute/resolver/impl/ChainingAttributeExtractor.cpp.orig	2013-09-29 09:10:24.000000000 +0000
+++ shibsp/attribute/resolver/impl/ChainingAttributeExtractor.cpp
@@ -170,7 +170,7 @@ ChainingAttributeExtractor::ChainingAttr
                 m_extractors.push_back(np.get());
                 np.release();
             }
-            catch (exception& ex) {
+            catch (std::exception& ex) {
                 Category::getInstance(SHIBSP_LOGCAT".AttributeExtractor.Chaining").error(
                     "caught exception processing embedded AttributeExtractor element: %s", ex.what()
                     );
