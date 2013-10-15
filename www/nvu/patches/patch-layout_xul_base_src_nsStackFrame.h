$NetBSD: patch-layout_xul_base_src_nsStackFrame.h,v 1.1 2013/10/15 14:49:35 joerg Exp $

--- layout/xul/base/src/nsStackFrame.h.orig	2013-10-14 22:38:42.000000000 +0000
+++ layout/xul/base/src/nsStackFrame.h
@@ -52,7 +52,7 @@ class nsStackFrame : public nsBoxFrame
 {
 public:
 
-  friend nsresult NS_NewStackFrame(nsIPresShell* aPresShell, nsIFrame** aNewFrame, nsIBoxLayout* aLayout = nsnull);
+  friend nsresult NS_NewStackFrame(nsIPresShell* aPresShell, nsIFrame** aNewFrame, nsIBoxLayout* aLayout);
 
 #ifdef NS_DEBUG
   NS_IMETHOD GetFrameName(nsAString& aResult) const
