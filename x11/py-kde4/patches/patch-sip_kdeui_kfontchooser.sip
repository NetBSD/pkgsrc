$NetBSD: patch-sip_kdeui_kfontchooser.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

sip 4.19.5 desn't like final arg, drop for now.

--- sip/kdeui/kfontchooser.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdeui/kfontchooser.sip
@@ -59,10 +59,10 @@ public:
 
     typedef QFlags<KFontChooser::DisplayFlag> DisplayFlags;
 
-    explicit                KFontChooser (QWidget* parent /TransferThis/ = 0, const KFontChooser::DisplayFlags& flags = KFontChooser::DisplayFrame, const QStringList& fontList = QStringList(), int visibleListSize = 8, Qt::CheckState* sizeIsRelativeState = 0) [(QWidget* = 0, const KFontChooser::DisplayFlags& = KFontChooser::DisplayFrame, const QStringList& = QStringList(), int = 8, Qt::CheckState* = 0)];
+    explicit                KFontChooser (QWidget* parent /TransferThis/ = 0, const KFontChooser::DisplayFlags& flags = KFontChooser::DisplayFrame, const QStringList& fontList = QStringList(), int visibleListSize = 8) [(QWidget* = 0, const KFontChooser::DisplayFlags& = KFontChooser::DisplayFrame, const QStringList& = QStringList(), int = 8)];
 %MethodCode
 Py_BEGIN_ALLOW_THREADS
-    sipCpp = new sipKFontChooser (a0, *a1, *a2, a3, &a4);
+    sipCpp = new sipKFontChooser (a0, *a1, *a2, a3);
     Py_END_ALLOW_THREADS
 %End
 
