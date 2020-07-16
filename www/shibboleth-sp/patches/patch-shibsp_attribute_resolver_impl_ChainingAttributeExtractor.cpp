--- shibsp/attribute/resolver/impl/ChainingAttributeExtractor.cpp.orig	2018-07-09 18:17:23.000000000 -0700
+++ shibsp/attribute/resolver/impl/ChainingAttributeExtractor.cpp	2020-07-07 12:26:19.008490542 -0700
@@ -139,7 +139,7 @@
                 m_extractors.push_back(np.get());
                 np.release();
             }
-            catch (const exception& ex) {
+            catch (const std::exception& ex) {
                 Category::getInstance(SHIBSP_LOGCAT ".AttributeExtractor.Chaining").error(
                     "caught exception processing embedded AttributeExtractor element: %s", ex.what()
                     );
