$NetBSD: patch-iocore_cache_CacheTest.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- iocore/cache/CacheTest.cc.orig	2020-05-13 23:47:50.206492571 +0000
+++ iocore/cache/CacheTest.cc
@@ -552,7 +552,7 @@ test_RamCache(RegressionTest *t, RamCach
 
   for (int l = 0; l < 10; l++) {
     for (int i = 0; i < 200; i++) {
-      IOBufferData *d = THREAD_ALLOC(ioDataAllocator, this_thread());
+      IOBufferData *d = THREAD_ALLOC(ioDataAllocator, ::this_thread());
       INK_MD5 md5;
 
       d->alloc(BUFFER_SIZE_INDEX_16K);
@@ -598,7 +598,7 @@ test_RamCache(RegressionTest *t, RamCach
     md5.u64[1] = ((uint64_t)r[i] << 32) + r[i];
     Ptr<IOBufferData> get_data;
     if (!cache->get(&md5, &get_data)) {
-      IOBufferData *d = THREAD_ALLOC(ioDataAllocator, this_thread());
+      IOBufferData *d = THREAD_ALLOC(ioDataAllocator, ::this_thread());
       d->alloc(BUFFER_SIZE_INDEX_16K);
       data.push_back(make_ptr(d));
       cache->put(&md5, data.back().get(), 1 << 15);
@@ -617,7 +617,7 @@ test_RamCache(RegressionTest *t, RamCach
     md5.u64[1] = ((uint64_t)r[i] << 32) + r[i];
     Ptr<IOBufferData> get_data;
     if (!cache->get(&md5, &get_data)) {
-      IOBufferData *d = THREAD_ALLOC(ioDataAllocator, this_thread());
+      IOBufferData *d = THREAD_ALLOC(ioDataAllocator, ::this_thread());
       d->alloc(BUFFER_SIZE_INDEX_8K + (r[i] % 3));
       data.push_back(make_ptr(d));
       cache->put(&md5, data.back().get(), d->block_size());
