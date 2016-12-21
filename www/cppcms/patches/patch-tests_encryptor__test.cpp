$NetBSD: patch-tests_encryptor__test.cpp,v 1.1 2016/12/21 13:39:21 joerg Exp $

Resolve ambiguity with NetBSD's hmac function.

--- tests/encryptor_test.cpp.orig	2016-12-21 00:15:55.815196132 +0000
+++ tests/encryptor_test.cpp
@@ -131,12 +131,12 @@ void test_crypto()
 	}
 	std::cout << "-- testing hmac-sha1/md5" << std::endl;
 	{
-		hmac d("md5",key("Jefe",4));
+		cppcms::crypto::hmac d("md5",key("Jefe",4));
 		TEST(get_diget(d,"what do ya want for nothing?") == "750c783e6ab0b503eaa86e310a5db738");
 	}
 	{
 		char const *bk = "xxxxxxxxxxxxxxddddddddddddddddddffffffffffffffffffffffffffffffffffffffffffffffdddddddddddddddddddd";
-		hmac d(message_digest::md5(),key(bk,strlen(bk)));
+		cppcms::crypto::hmac d(message_digest::md5(),key(bk,strlen(bk)));
 		TEST(get_diget(d,"what do ya want for nothing?") == "4891f8cf6a4641897159756847369d1a");
 	}
 
