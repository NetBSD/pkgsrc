$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_src_trace__processor_db_column_utils.cc,v 1.1 2025/12/21 09:38:44 markd Exp $

for std::floor and std::ceil on NetBSD   XXXXX

--- src/3rdparty/chromium/third_party/perfetto/src/trace_processor/db/column/utils.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/src/trace_processor/db/column/utils.cc
@@ -50,12 +50,12 @@ SearchValidationResult CompareIntColumnW
 
     case FilterOp::kLe:
     case FilterOp::kGt:
-      *sql_val = SqlValue::Long(static_cast<int64_t>(std::floor(double_val)));
+      *sql_val = SqlValue::Long(static_cast<int64_t>(floor(double_val)));
       return SearchValidationResult::kOk;
 
     case FilterOp::kLt:
     case FilterOp::kGe:
-      *sql_val = SqlValue::Long(static_cast<int64_t>(std::ceil(double_val)));
+      *sql_val = SqlValue::Long(static_cast<int64_t>(ceil(double_val)));
       return SearchValidationResult::kOk;
 
     case FilterOp::kIsNotNull:
