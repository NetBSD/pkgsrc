$NetBSD: patch-qtwebkit_Source_WebCore_editing_Editor.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtwebkit/Source/WebCore/editing/Editor.h.orig	2013-11-27 01:01:43.000000000 +0000
+++ qtwebkit/Source/WebCore/editing/Editor.h
@@ -416,7 +416,7 @@ public:
     Vector<String> dictationAlternativesForMarker(const DocumentMarker*);
     void applyDictationAlternativelternative(const String& alternativeString);
 private:
-    virtual void willDetachPage() OVERRIDE;
+    virtual void willDetachPage();
 
 #if ENABLE(DELETION_UI)
     OwnPtr<DeleteButtonController> m_deleteButtonController;
