$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_runtime_Structure.cpp,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/javascriptcore/JavaScriptCore/runtime/Structure.cpp.orig	2013-05-08 13:07:22.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/runtime/Structure.cpp
@@ -156,9 +156,10 @@ Structure::Structure(JSValue prototype, 
 Structure::~Structure()
 {
     if (m_previous) {
-        if (m_nameInPrevious)
-            m_previous->table.remove(StructureTransitionTableHash::Key(RefPtr<UString::Rep>(m_nameInPrevious.get()), m_attributesInPrevious), m_specificValueInPrevious);
-        else
+        if (m_nameInPrevious) {
+            unsigned attrPrev = m_attributesInPrevious;
+            m_previous->table.remove(StructureTransitionTableHash::Key(RefPtr<UString::Rep>(m_nameInPrevious.get()), attrPrev), m_specificValueInPrevious);
+        } else
             m_previous->table.removeAnonymousSlotTransition(m_anonymousSlotsInPrevious);
 
     }
