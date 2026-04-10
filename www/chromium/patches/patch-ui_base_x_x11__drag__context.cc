$NetBSD: patch-ui_base_x_x11__drag__context.cc,v 1.2 2026/04/10 17:32:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/x/x11_drag_context.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ ui/base/x/x11_drag_context.cc
@@ -15,7 +15,7 @@
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #include "ui/base/x/selection_utils.h"
@@ -150,7 +150,7 @@ void XDragContext::OnSelectionNotify(con
     scoped_refptr<base::RefCountedMemory> data;
     x11::Atom type = x11::Atom::None;
     if (GetRawBytesOfProperty(local_window_, property, &data, &type)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // If the source provided a portal key, retrieve the files now.
       if (target == x11::GetAtom(kMimeTypePortalFileTransfer) ||
           target == x11::GetAtom(kMimeTypePortalFiles)) {
