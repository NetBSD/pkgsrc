$NetBSD: patch-mozilla_js_src_jsgc.cpp,v 1.5 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/jsgc.cpp.orig	2013-06-20 04:35:08.000000000 +0000
+++ mozilla/js/src/jsgc.cpp
@@ -478,13 +478,15 @@ FinalizeArenas(FreeOp *fop,
 }
 
 static inline Chunk *
-AllocChunk() {
-    return static_cast<Chunk *>(MapAlignedPages(ChunkSize, ChunkSize));
+AllocChunk(JSRuntime *rt)
+{
+    return static_cast<Chunk *>(MapAlignedPages(rt, ChunkSize, ChunkSize));
 }
 
 static inline void
-FreeChunk(Chunk *p) {
-    UnmapPages(static_cast<void *>(p), ChunkSize);
+FreeChunk(JSRuntime *rt, Chunk *p)
+{
+    UnmapPages(rt, static_cast<void *>(p), ChunkSize);
 }
 
 inline bool
@@ -574,25 +576,25 @@ ChunkPool::expire(JSRuntime *rt, bool re
 }
 
 static void
-FreeChunkList(Chunk *chunkListHead)
+FreeChunkList(JSRuntime *rt, Chunk *chunkListHead)
 {
     while (Chunk *chunk = chunkListHead) {
         JS_ASSERT(!chunk->info.numArenasFreeCommitted);
         chunkListHead = chunk->info.next;
-        FreeChunk(chunk);
+        FreeChunk(rt, chunk);
     }
 }
 
 void
 ChunkPool::expireAndFree(JSRuntime *rt, bool releaseAll)
 {
-    FreeChunkList(expire(rt, releaseAll));
+    FreeChunkList(rt, expire(rt, releaseAll));
 }
 
 /* static */ Chunk *
 Chunk::allocate(JSRuntime *rt)
 {
-    Chunk *chunk = static_cast<Chunk *>(AllocChunk());
+    Chunk *chunk = AllocChunk(rt);
 
 #ifdef JSGC_ROOT_ANALYSIS
     // Our poison pointers are not guaranteed to be invalid on 64-bit
@@ -605,7 +607,7 @@ Chunk::allocate(JSRuntime *rt)
     // were marked as uncommitted, but it's a little complicated to avoid
     // clobbering pre-existing unrelated mappings.
     while (IsPoisonedPtr(chunk))
-        chunk = static_cast<Chunk *>(AllocChunk());
+        chunk = AllocChunk(rt);
 #endif
 
     if (!chunk)
@@ -621,7 +623,7 @@ Chunk::release(JSRuntime *rt, Chunk *chu
 {
     JS_ASSERT(chunk);
     chunk->prepareToBeFreed(rt);
-    FreeChunk(chunk);
+    FreeChunk(rt, chunk);
 }
 
 inline void
@@ -749,7 +751,7 @@ Chunk::fetchNextDecommittedArena()
     decommittedArenas.unset(offset);
 
     Arena *arena = &arenas[offset];
-    MarkPagesInUse(arena, ArenaSize);
+    MarkPagesInUse(info.runtime, arena, ArenaSize);
     arena->aheader.setAsNotAllocated();
 
     return &arena->aheader;
@@ -948,6 +950,8 @@ static const int64_t JIT_SCRIPT_RELEASE_
 JSBool
 js_InitGC(JSRuntime *rt, uint32_t maxbytes)
 {
+    InitMemorySubsystem(rt);
+
     if (!rt->gcChunkSet.init(INITIAL_CHUNK_CAPACITY))
         return false;
 
@@ -2024,6 +2028,9 @@ js::MaybeGC(JSContext *cx)
 static void
 DecommitArenasFromAvailableList(JSRuntime *rt, Chunk **availableListHeadp)
 {
+    if (!DecommitEnabled(rt))
+        return;
+
     Chunk *chunk = *availableListHeadp;
     if (!chunk)
         return;
@@ -2075,7 +2082,7 @@ DecommitArenasFromAvailableList(JSRuntim
                 Maybe<AutoUnlockGC> maybeUnlock;
                 if (!rt->isHeapBusy())
                     maybeUnlock.construct(rt);
-                ok = MarkPagesUnused(aheader->getArena(), ArenaSize);
+                ok = MarkPagesUnused(rt, aheader->getArena(), ArenaSize);
             }
 
             if (ok) {
@@ -2105,7 +2112,7 @@ DecommitArenasFromAvailableList(JSRuntim
                 JS_ASSERT(chunk->info.prevp);
             }
 
-            if (rt->gcChunkAllocationSinceLastGC) {
+            if (rt->gcChunkAllocationSinceLastGC || !ok) {
                 /*
                  * The allocator thread has started to get new chunks. We should stop
                  * to avoid decommitting arenas in just allocated chunks.
@@ -2143,7 +2150,7 @@ ExpireChunksAndArenas(JSRuntime *rt, boo
 {
     if (Chunk *toFree = rt->gcChunkPool.expire(rt, shouldShrink)) {
         AutoUnlockGC unlock(rt);
-        FreeChunkList(toFree);
+        FreeChunkList(rt, toFree);
     }
 
     if (shouldShrink)
