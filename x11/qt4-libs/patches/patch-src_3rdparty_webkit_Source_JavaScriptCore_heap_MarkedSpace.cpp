$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_heap_MarkedSpace.cpp,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/heap/MarkedSpace.cpp.orig	2013-05-08 14:48:50.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/heap/MarkedSpace.cpp
@@ -124,8 +124,8 @@ void MarkedSpace::sweep()
 size_t MarkedSpace::objectCount() const
 {
     size_t result = 0;
-    BlockIterator end = m_blocks.end();
-    for (BlockIterator it = m_blocks.begin(); it != end; ++it)
+    ConstBlockIterator end = m_blocks.end();
+    for (ConstBlockIterator it = m_blocks.begin(); it != end; ++it)
         result += (*it)->markCount();
     return result;
 }
@@ -133,8 +133,8 @@ size_t MarkedSpace::objectCount() const
 size_t MarkedSpace::size() const
 {
     size_t result = 0;
-    BlockIterator end = m_blocks.end();
-    for (BlockIterator it = m_blocks.begin(); it != end; ++it)
+    ConstBlockIterator end = m_blocks.end();
+    for (ConstBlockIterator it = m_blocks.begin(); it != end; ++it)
         result += (*it)->size();
     return result;
 }
@@ -142,8 +142,8 @@ size_t MarkedSpace::size() const
 size_t MarkedSpace::capacity() const
 {
     size_t result = 0;
-    BlockIterator end = m_blocks.end();
-    for (BlockIterator it = m_blocks.begin(); it != end; ++it)
+    ConstBlockIterator end = m_blocks.end();
+    for (ConstBlockIterator it = m_blocks.begin(); it != end; ++it)
         result += (*it)->capacity();
     return result;
 }
