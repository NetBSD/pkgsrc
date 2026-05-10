$NetBSD: patch-ui_base_x_selection__owner.h,v 1.1 2026/05/10 15:30:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/x/selection_owner.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ ui/base/x/selection_owner.h
@@ -19,7 +19,7 @@
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/event.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/weak_ptr.h"
 #endif
 
@@ -136,7 +136,7 @@ class COMPONENT_EXPORT(UI_BASE_X) Select
   std::vector<IncrementalTransfer>::iterator FindIncrementalTransferForEvent(
       const x11::PropertyNotifyEvent& event);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnPortalPathsRegistered(x11::SelectionRequestEvent request,
                                std::string key);
 #endif
@@ -160,7 +160,7 @@ class COMPONENT_EXPORT(UI_BASE_X) Select
   // Used to abort stale incremental data transfers.
   base::RepeatingTimer incremental_transfer_abort_timer_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::WeakPtrFactory<SelectionOwner> weak_factory_{this};
 #endif
 };
