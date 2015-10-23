$NetBSD: patch-shibsp_attribute_resolver_impl_ChainingAttributeResolver.cpp,v 1.2 2015/10/23 07:35:08 pettai Exp $

--- shibsp/attribute/resolver/impl/ChainingAttributeResolver.cpp.orig	2015-10-19 17:29:03.000000000 -0700
+++ shibsp/attribute/resolver/impl/ChainingAttributeResolver.cpp	2015-10-19 17:29:32.000000000 -0700
@@ -240,7 +240,7 @@
                 m_resolvers.push_back(np.get());
                 np.release();
             }
-            catch (exception& ex) {
+            catch (std::exception& ex) {
                 Category::getInstance(SHIBSP_LOGCAT ".AttributeResolver." CHAINING_ATTRIBUTE_RESOLVER).error(
                     "caught exception processing embedded AttributeResolver element: %s", ex.what()
                     );
@@ -274,7 +274,7 @@
             chain.m_ownedAssertions.insert(chain.m_ownedAssertions.end(), context->getResolvedAssertions().begin(), context->getResolvedAssertions().end());
             context->getResolvedAssertions().clear();
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             Category::getInstance(SHIBSP_LOGCAT ".AttributeResolver." CHAINING_ATTRIBUTE_RESOLVER).error(
                 "caught exception applying AttributeResolver in chain: %s", ex.what()
                 );
