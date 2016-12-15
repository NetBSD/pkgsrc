$NetBSD: patch-mozilla_dom_smil_nsSMILTimeContainer.cpp,v 1.1 2016/12/15 07:48:19 dholland Exp $

Fix for CVE-2016-9079, aka
https://www.mozilla.org/en-US/security/advisories/mfsa2016-92/
from the firefox 45.5.1esr distfile,
which is the same as
https://hg.mozilla.org/integration/mozilla-inbound/rev/9271347b07d201df26cdffde75483c0b0001528c
linked from https://bugzilla.mozilla.org/show_bug.cgi?id=1321066

--- mozilla/dom/smil/nsSMILTimeContainer.cpp.orig	2016-01-19 02:48:35.000000000 +0000
+++ mozilla/dom/smil/nsSMILTimeContainer.cpp
@@ -9,6 +9,8 @@
 #include "nsSMILTimedElement.h"
 #include <algorithm>
 
+#include "mozilla/AutoRestore.h"
+
 nsSMILTimeContainer::nsSMILTimeContainer()
 :
   mParent(nullptr),
@@ -18,6 +20,7 @@ nsSMILTimeContainer::nsSMILTimeContainer
   mNeedsPauseSample(false),
   mNeedsRewind(false),
   mIsSeeking(false),
+  mHoldingEntries(false),
   mPauseState(PAUSE_BEGIN)
 {
 }
@@ -213,12 +216,14 @@ nsSMILTimeContainer::AddMilestone(const 
   // time may change (e.g. if attributes are changed on the timed element in
   // between samples). If this happens, then we may do an unecessary sample
   // but that's pretty cheap.
+  MOZ_RELEASE_ASSERT(!mHoldingEntries);
   return mMilestoneEntries.Push(MilestoneEntry(aMilestone, aElement));
 }
 
 void
 nsSMILTimeContainer::ClearMilestones()
 {
+  MOZ_RELEASE_ASSERT(!mHoldingEntries);
   mMilestoneEntries.Clear();
 }
 
@@ -259,6 +264,8 @@ nsSMILTimeContainer::PopMilestoneElement
              "Trying to pop off earliest times but we have earlier ones that "
              "were overlooked");
 
+  MOZ_RELEASE_ASSERT(!mHoldingEntries);
+
   bool gotOne = false;
   while (!mMilestoneEntries.IsEmpty() &&
       mMilestoneEntries.Top().mMilestone == containerMilestone)
@@ -273,6 +280,8 @@ nsSMILTimeContainer::PopMilestoneElement
 void
 nsSMILTimeContainer::Traverse(nsCycleCollectionTraversalCallback* aCallback)
 {
+  AutoRestore<bool> saveHolding(mHoldingEntries);
+  mHoldingEntries = true;
   const MilestoneEntry* p = mMilestoneEntries.Elements();
   while (p < mMilestoneEntries.Elements() + mMilestoneEntries.Length()) {
     NS_CYCLE_COLLECTION_NOTE_EDGE_NAME(*aCallback, "mTimebase");
@@ -284,6 +293,7 @@ nsSMILTimeContainer::Traverse(nsCycleCol
 void
 nsSMILTimeContainer::Unlink()
 {
+  MOZ_RELEASE_ASSERT(!mHoldingEntries);
   mMilestoneEntries.Clear();
 }
 
@@ -307,6 +317,8 @@ nsSMILTimeContainer::NotifyTimeChange()
   // milestone elements. This is because any timed element with dependents and
   // with significant transitions yet to fire should have their next milestone
   // registered. Other timed elements don't matter.
+  AutoRestore<bool> saveHolding(mHoldingEntries);
+  mHoldingEntries = true;
   const MilestoneEntry* p = mMilestoneEntries.Elements();
 #if DEBUG
   uint32_t queueLength = mMilestoneEntries.Length();
