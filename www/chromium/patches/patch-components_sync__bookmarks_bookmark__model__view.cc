$NetBSD: patch-components_sync__bookmarks_bookmark__model__view.cc,v 1.25 2026/11/19 19:46:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_bookmarks/bookmark_model_view.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/sync_bookmarks/bookmark_model_view.cc
@@ -10,7 +10,7 @@
 #include "components/bookmarks/browser/bookmark_node.h"
 #include "components/bookmarks/common/bookmark_metrics.h"
 #include "components/sync_bookmarks/scoped_bookmark_extensive_changes.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/metrics/histogram_base.h"
 #include "base/metrics/histogram_functions.h"
 #include "base/time/time.h"
@@ -252,7 +252,7 @@ void BookmarkModelViewUsingAccountNodes:
 
 void BookmarkModelViewUsingAccountNodes::
     MaybeRemoveUnderlyingModelDuplicatesUponInitialSync() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::Time deduplication_start_time = base::Time::Now();
 
   InitialAccountBookmarkDeduplicator initial_account_bookmark_deduplicator(
