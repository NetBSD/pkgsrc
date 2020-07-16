--- shibsp/attribute/filtering/impl/XMLAttributeFilter.cpp.orig	2020-04-01 16:27:44.000000000 -0700
+++ shibsp/attribute/filtering/impl/XMLAttributeFilter.cpp	2020-07-07 12:23:32.612919412 -0700
@@ -259,7 +259,7 @@
             functorMap.getMatchFunctors().insert(multimap<string,MatchFunctor*>::value_type(id, func.get()));
             return func.release();
         }
-        catch (const exception& ex) {
+        catch (const std::exception& ex) {
             m_log.error("error building %s with type (%s): %s", logname, type->toString().c_str(), ex.what());
         }
     }
