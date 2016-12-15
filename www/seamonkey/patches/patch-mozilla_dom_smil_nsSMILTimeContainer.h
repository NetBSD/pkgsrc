$NetBSD: patch-mozilla_dom_smil_nsSMILTimeContainer.h,v 1.1 2016/12/15 07:48:19 dholland Exp $

Fix for CVE-2016-9079, aka
https://www.mozilla.org/en-US/security/advisories/mfsa2016-92/
from the firefox 45.5.1esr distfile,
which is the same as
https://hg.mozilla.org/integration/mozilla-inbound/rev/9271347b07d201df26cdffde75483c0b0001528c
linked from https://bugzilla.mozilla.org/show_bug.cgi?id=1321066

--- mozilla/dom/smil/nsSMILTimeContainer.h.orig	2016-01-19 02:49:17.000000000 +0000
+++ mozilla/dom/smil/nsSMILTimeContainer.h
@@ -267,6 +267,8 @@ protected:
   bool mNeedsRewind; // Backwards seek performed
   bool mIsSeeking; // Currently in the middle of a seek operation
 
+  bool mHoldingEntries; // True if there's a raw pointer to mMilestoneEntries on the stack.
+
   // A bitfield of the pause state for all pause requests
   uint32_t mPauseState;
 
