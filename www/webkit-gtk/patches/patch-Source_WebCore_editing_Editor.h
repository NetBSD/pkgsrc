$NetBSD: patch-Source_WebCore_editing_Editor.h,v 1.1 2012/10/24 15:40:16 joerg Exp $

--- Source/WebCore/editing/Editor.h.orig	2012-10-23 16:11:11.000000000 +0000
+++ Source/WebCore/editing/Editor.h
@@ -385,7 +385,7 @@ public:
     void deviceScaleFactorChanged();
 
 private:
-    virtual void willDetachPage() OVERRIDE;
+    virtual void willDetachPage();
 
     OwnPtr<DeleteButtonController> m_deleteButtonController;
     RefPtr<CompositeEditCommand> m_lastEditCommand;
