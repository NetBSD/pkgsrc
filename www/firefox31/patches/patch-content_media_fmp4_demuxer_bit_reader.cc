$NetBSD: patch-content_media_fmp4_demuxer_bit_reader.cc,v 1.1 2014/11/03 12:18:32 ryoon Exp $

Fix build with pre-C++11 compilers like G++ 4.5.3.

--- content/media/fmp4/demuxer/bit_reader.cc.orig	2014-07-17 02:45:09.000000000 +0100
+++ content/media/fmp4/demuxer/bit_reader.cc	2014-07-25 13:00:34.000000000 +0100
@@ -9,7 +9,7 @@
 
 BitReader::BitReader(const uint8_t* data, off_t size)
     : data_(data), bytes_left_(size), num_remaining_bits_in_curr_byte_(0) {
-  DCHECK(data_ != nullptr && bytes_left_ > 0);
+  DCHECK(data_ != 0 && bytes_left_ > 0);
 
   UpdateCurrByte();
 }
