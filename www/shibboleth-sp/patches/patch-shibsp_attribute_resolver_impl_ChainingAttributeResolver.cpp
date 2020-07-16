--- shibsp/attribute/resolver/impl/ChainingAttributeResolver.cpp.orig	2018-07-09 18:17:23.000000000 -0700
+++ shibsp/attribute/resolver/impl/ChainingAttributeResolver.cpp	2020-07-07 12:26:03.316192576 -0700
@@ -197,7 +197,7 @@
                 m_resolvers.push_back(np.get());
                 np.release();
             }
-            catch (const exception& ex) {
+            catch (const std::exception& ex) {
                 Category::getInstance(SHIBSP_LOGCAT ".AttributeResolver." CHAINING_ATTRIBUTE_RESOLVER).error(
                     "caught exception processing embedded AttributeResolver element: %s", ex.what()
                     );
@@ -231,7 +231,7 @@
             chain.m_ownedAssertions.insert(chain.m_ownedAssertions.end(), context->getResolvedAssertions().begin(), context->getResolvedAssertions().end());
             context->getResolvedAssertions().clear();
         }
-        catch (const exception& ex) {
+        catch (const std::exception& ex) {
             Category::getInstance(SHIBSP_LOGCAT ".AttributeResolver." CHAINING_ATTRIBUTE_RESOLVER).error(
                 "caught exception applying AttributeResolver in chain: %s", ex.what()
                 );
