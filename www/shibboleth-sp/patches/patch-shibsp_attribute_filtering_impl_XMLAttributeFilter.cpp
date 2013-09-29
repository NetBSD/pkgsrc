$NetBSD: patch-shibsp_attribute_filtering_impl_XMLAttributeFilter.cpp,v 1.1 2013/09/29 10:19:47 joerg Exp $

--- shibsp/attribute/filtering/impl/XMLAttributeFilter.cpp.orig	2013-09-29 08:53:37.000000000 +0000
+++ shibsp/attribute/filtering/impl/XMLAttributeFilter.cpp
@@ -249,7 +249,7 @@ MatchFunctor* XMLFilterImpl::buildFuncto
             functorMap.getMatchFunctors().insert(multimap<string,MatchFunctor*>::value_type(id, func.get()));
             return func.release();
         }
-        catch (exception& ex) {
+        catch (std::exception& ex) {
             m_log.error("error building %s with type (%s): %s", logname, type->toString().c_str(), ex.what());
         }
     }
