$NetBSD: patch-sip_kdeui_kfontdialog.sip,v 1.1 2018/01/17 19:21:20 markd Exp $

sip 4.19.5 desn't like final arg, drop for now. 

--- sip/kdeui/kfontdialog.sip.orig	2014-08-14 20:17:11.000000000 +0000
+++ sip/kdeui/kfontdialog.sip
@@ -28,10 +28,10 @@ class KFontDialog : KDialog
 
 
 public:
-    explicit                KFontDialog (QWidget* parent /TransferThis/ = 0, const KFontChooser::DisplayFlags& flags = KFontChooser::NoDisplayFlags, const QStringList& fontlist = QStringList(), Qt::CheckState* sizeIsRelativeState = 0) [(QWidget* = 0, const KFontChooser::DisplayFlags& = KFontChooser::NoDisplayFlags, const QStringList& = QStringList(), Qt::CheckState* = 0)];
+    explicit                KFontDialog (QWidget* parent /TransferThis/ = 0, const KFontChooser::DisplayFlags& flags = KFontChooser::NoDisplayFlags, const QStringList& fontlist = QStringList()) [(QWidget* = 0, const KFontChooser::DisplayFlags& = KFontChooser::NoDisplayFlags, const QStringList& = QStringList())];
 %MethodCode
 Py_BEGIN_ALLOW_THREADS
-    sipCpp= new sipKFontDialog (a0, *a1, *a2, &a3);
+    sipCpp= new sipKFontDialog (a0, *a1, *a2);
     Py_END_ALLOW_THREADS
 %End
 
