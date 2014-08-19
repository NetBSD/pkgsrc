$NetBSD: patch-src_engine_generate.cpp,v 1.1 2014/08/19 13:43:37 joerg Exp $

--- src/engine/generate.cpp.orig	2014-08-19 12:46:36.000000000 +0000
+++ src/engine/generate.cpp
@@ -2600,7 +2600,7 @@ void Generate::generate(int maxSeconds, 
 	}
 
 if(threaded){
-		mutex.lock();
+		::mutex.lock();
 }
 	c.makeUnallocated(gt.rules);
 
@@ -2616,7 +2616,7 @@ if(threaded){
 	maxActivitiesPlaced=0;
 
 if(threaded){
-		mutex.unlock();
+		::mutex.unlock();
 }
 
 	triedRemovals.resize(gt.rules.nInternalActivities, gt.rules.nHoursPerWeek);
@@ -2649,13 +2649,13 @@ if(threaded){
 	time(&starting_time);
 	
 if(threaded){
-		mutex.lock();
+		::mutex.lock();
 }
 	timeToHighestStage=0;
 	searchTime=0;
 	generationStartDateTime=QDateTime::currentDateTime();
 if(threaded){
-		mutex.unlock();
+		::mutex.unlock();
 }
 	
 	//2000 was before
@@ -2670,11 +2670,11 @@ if(threaded){
 		prevvalue:
 
 if(threaded){
-		mutex.lock();
+		::mutex.lock();
 }
 		if(abortOptimization){
 if(threaded){
-			mutex.unlock();
+			::mutex.unlock();
 }
 			return;
 		}
@@ -2684,7 +2684,7 @@ if(threaded){
 		
 		if(searchTime>=maxSeconds){
 if(threaded){
-			mutex.unlock();
+			::mutex.unlock();
 }
 			
 			timeExceeded=true;
@@ -2949,7 +2949,7 @@ if(threaded){
 		if(!foundGoodSwap){
 			if(impossibleActivity){
 if(threaded){
-				mutex.unlock();
+				::mutex.unlock();
 }
 				nDifficultActivities=1;
 				difficultActivities[0]=permutation[added_act];
@@ -3079,7 +3079,7 @@ if(threaded){
 				
 			added_act=q+1;
 if(threaded){
-			mutex.unlock();
+			::mutex.unlock();
 }
 	
 			//if(semaphorePlacedActivity){
@@ -3123,18 +3123,18 @@ if(threaded){
 			}
 			
 if(threaded){
-			mutex.unlock();
+			::mutex.unlock();
 }
 			emit(activityPlaced(added_act+1));
 if(threaded){
 			semaphorePlacedActivity.acquire();
 }
 if(threaded){
-			mutex.lock();
+			::mutex.lock();
 }
 			if(added_act==gt.rules.nInternalActivities && foundGoodSwap){
 if(threaded){
-				mutex.unlock();
+				::mutex.unlock();
 }
 				break;
 			}
@@ -3154,7 +3154,7 @@ if(threaded){
 		}
 
 if(threaded){
-		mutex.unlock();
+		::mutex.unlock();
 }
 	}
 
@@ -9123,8 +9123,8 @@ skip_here_if_already_allocated_in_time:
 	if(level==0 && (nConflActivities[perm[0]]==MAX_ACTIVITIES)){
 		//to check if generation was stopped
 if(this->isThreaded){
-			mutex.unlock();
-			mutex.lock();
+			::mutex.unlock();
+			::mutex.lock();
 }
 		if(!abortOptimization && activity_count_impossible_tries<MAX_RETRIES_FOR_AN_ACTIVITY_AT_LEVEL_0){
 			activity_count_impossible_tries++;
