$NetBSD: patch-shibsp_attribute_resolver_impl_ChainingAttributeResolver.cpp,v 1.1 2013/09/29 10:19:47 joerg Exp $

--- shibsp/attribute/resolver/impl/ChainingAttributeResolver.cpp.orig	2013-09-29 08:55:53.000000000 +0000
+++ shibsp/attribute/resolver/impl/ChainingAttributeResolver.cpp
@@ -240,7 +240,7 @@ ChainingAttributeResolver::ChainingAttri
                 m_resolvers.push_back(np.get());
                 np.release();
             }
-            catch (exception& ex) {
+            catch (std::exception& ex) {
                 Category::getInstance(SHIBSP_LOGCAT".AttributeResolver."CHAINING_ATTRIBUTE_RESOLVER).error(
                     "caught exception processing embedded AttributeResolver element: %s", ex.what()
                     );
@@ -274,7 +274,7 @@ void ChainingAttributeResolver::resolveA
             chain.m_ownedAssertions.insert(chain.m_ownedAssertions.end(), context->getResolvedAssertions().begin(), context->getResolvedAssertions().end());
             context->getResolvedAssertions().clear();
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             Category::getInstance(SHIBSP_LOGCAT".AttributeResolver."CHAINING_ATTRIBUTE_RESOLVER).error(
                 "caught exception applying AttributeResolver in chain: %s", ex.what()
                 );
