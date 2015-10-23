$NetBSD: patch-shibsp_attribute_resolver_impl_ChainingAttributeExtractor.cpp,v 1.2 2015/10/23 07:35:08 pettai Exp $

--- shibsp/attribute/resolver/impl/ChainingAttributeExtractor.cpp.orig	2015-10-19 17:27:55.000000000 -0700
+++ shibsp/attribute/resolver/impl/ChainingAttributeExtractor.cpp	2015-10-19 17:28:27.000000000 -0700
@@ -170,7 +170,7 @@
                 m_extractors.push_back(np.get());
                 np.release();
             }
-            catch (exception& ex) {
+            catch (std::exception& ex) {
                 Category::getInstance(SHIBSP_LOGCAT ".AttributeExtractor.Chaining").error(
                     "caught exception processing embedded AttributeExtractor element: %s", ex.what()
                     );
