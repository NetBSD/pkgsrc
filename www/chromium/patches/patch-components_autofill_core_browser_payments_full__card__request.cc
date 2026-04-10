$NetBSD: patch-components_autofill_core_browser_payments_full__card__request.cc,v 1.2 2026/04/10 17:31:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/full_card_request.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ components/autofill/core/browser/payments/full_card_request.cc
@@ -124,7 +124,7 @@ void FullCardRequest::GetFullCardImpl(
   request_->card = std::move(card);
   request_->last_committed_primary_main_frame_origin =
       last_committed_primary_main_frame_origin;
-  request_->context_token = std::move(context_token).value_or({});
+  request_->context_token = std::move(context_token).value_or(std::string{});
   request_->selected_challenge_option = std::move(selected_challenge_option);
 
   should_unmask_card_ = request_->card.masked() ||
