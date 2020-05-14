$NetBSD: patch-plugins_tcpinfo_tcpinfo.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- plugins/tcpinfo/tcpinfo.cc.orig	2020-05-14 00:21:57.897681609 +0000
+++ plugins/tcpinfo/tcpinfo.cc
@@ -134,7 +134,7 @@ log_tcp_info(Config *config, const char 
   TSReturnCode ret;
 
   if (config->log_level == 2) {
-#if !defined(freebsd) || defined(__GLIBC__)
+#if (!defined(netbsd) && !defined(freebsd)) || defined(__GLIBC__)
     ret = TSTextLogObjectWrite(config->log, "%s %s %s %u %u %u %u %u %u %u %u %u %u %u %u", event_name, client_str, server_str,
                                info.tcpi_rtt, info.tcpi_rttvar, info.tcpi_last_data_sent, info.tcpi_last_data_recv,
                                info.tcpi_snd_cwnd, info.tcpi_snd_ssthresh, info.tcpi_rcv_ssthresh, info.tcpi_unacked,
