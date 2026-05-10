$NetBSD: patch-components_sync__bookmarks_bookmark__model__view.cc,v 1.11 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_bookmarks/bookmark_model_view.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/sync_bookmarks/bookmark_model_view.cc
@@ -9,7 +9,7 @@
 #include "components/bookmarks/browser/bookmark_model.h"
 #include "components/bookmarks/browser/bookmark_node.h"
 #include "components/bookmarks/common/bookmark_metrics.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_base.h"
 #include "base/metrics/histogram_functions.h"
 #include "base/time/time.h"
@@ -253,7 +253,7 @@ void BookmarkModelViewUsingAccountNodes:
 
 void BookmarkModelViewUsingAccountNodes::
     MaybeRemoveUnderlyingModelDuplicatesUponInitialSync() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BeginExtensiveChanges();
 
   const base::Time deduplication_start_time = base::Time::Now();
