$NetBSD: patch-net_quic_quic__network__transaction__unittest.cc,v 1.3 2025/07/25 16:17:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/quic/quic_network_transaction_unittest.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ net/quic/quic_network_transaction_unittest.cc
@@ -5202,10 +5202,10 @@ TEST_P(QuicNetworkTransactionTest, RstSt
 
 TEST_P(QuicNetworkTransactionTest, BrokenAlternateProtocol) {
   // Alternate-protocol job
-  std::unique_ptr<quic::QuicEncryptedPacket> close(
+  std::unique_ptr<quic::QuicEncryptedPacket> test_close(
       ConstructServerConnectionClosePacket(1));
   MockRead quic_reads[] = {
-      MockRead(ASYNC, close->data(), close->length()),
+      MockRead(ASYNC, test_close->data(), test_close->length()),
       MockRead(ASYNC, ERR_IO_PENDING),  // No more data to read
       MockRead(ASYNC, OK),              // EOF
   };
@@ -5248,10 +5248,10 @@ TEST_P(QuicNetworkTransactionTest,
   http_server_properties_ = std::make_unique<HttpServerProperties>();
 
   // Alternate-protocol job
-  std::unique_ptr<quic::QuicEncryptedPacket> close(
+  std::unique_ptr<quic::QuicEncryptedPacket> test_close(
       ConstructServerConnectionClosePacket(1));
   MockRead quic_reads[] = {
-      MockRead(ASYNC, close->data(), close->length()),
+      MockRead(ASYNC, test_close->data(), test_close->length()),
       MockRead(ASYNC, ERR_IO_PENDING),  // No more data to read
       MockRead(ASYNC, OK),              // EOF
   };
