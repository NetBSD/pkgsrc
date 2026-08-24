$NetBSD: patch-src_modules_battery.cpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Add NetBSD support
* Use udev only for linux

--- src/modules/battery.cpp.orig	2026-02-06 20:15:03.000000000 +0000
+++ src/modules/battery.cpp
@@ -2,15 +2,79 @@
 
 #include <algorithm>
 #include <cctype>
+#include <cstddef>
 
 #include "util/command.hpp"
 #if defined(__FreeBSD__)
 #include <sys/sysctl.h>
 #endif
+#ifdef HAVE_LIBUDEV
 #include <libudev.h>
 #include <poll.h>
-#include <spdlog/spdlog.h>
 #include <sys/signalfd.h>
+#endif
+#include <spdlog/spdlog.h>
+
+#if defined(__NetBSD__)
+#include <fcntl.h>
+#include <unistd.h>
+#include <prop/proplib.h>
+#include <sys/envsys.h>
+
+#define SYSMON "/dev/sysmon"
+
+static prop_array_t get_device(const char* name) {
+  prop_dictionary_t dict;
+  prop_object_t obj;
+  prop_array_t array;
+  int fd;
+
+  if (name == nullptr) { return nullptr; }
+  if ((fd = open(SYSMON, O_RDONLY)) < 0) { return nullptr; }
+  if (prop_dictionary_recv_ioctl(fd, ENVSYS_GETDICTIONARY, &dict) != 0) {
+    close(fd);
+    return nullptr;
+  }
+  close(fd);
+
+  if ((obj = prop_dictionary_get(dict, name)) == nullptr) {
+    prop_object_release(dict);
+    return nullptr;
+  }
+  if (prop_object_type(obj) != PROP_TYPE_ARRAY) {
+    prop_object_release(dict);
+    return nullptr;
+  }
+
+  array = (prop_array_t)obj;
+  prop_object_retain(array);
+  prop_object_release(dict);
+
+  return array;
+}
+
+static int64_t handle_stat(prop_dictionary_t stat, const char * key) {
+  prop_object_t obj;
+
+  if ((stat == nullptr || key == nullptr) ||
+      ((obj = prop_dictionary_get(stat, key)) == nullptr) ||
+      (prop_object_type(obj) != PROP_TYPE_NUMBER))
+  { return -1; }
+
+  return prop_number_signed_value((prop_number_t)obj);
+}
+
+static bool stat_is_valid(prop_dictionary_t stat) {
+  prop_object_t obj;
+
+  if ((stat == nullptr) ||
+      ((obj = prop_dictionary_get(stat, "state")) == nullptr) ||
+      (prop_object_type(obj) != PROP_TYPE_STRING))
+  { return false; }
+
+  return prop_string_equals_string((prop_string_t)obj, "valid");
+}
+#endif
 
 waybar::modules::Battery::Battery(const std::string& id, const Bar& bar, const Json::Value& config)
     : ALabel(config, "battery", id, "{capacity}%", 60), last_event_(""), bar_(bar) {
@@ -56,7 +120,7 @@ waybar::modules::Battery::~Battery() {
 }
 
 void waybar::modules::Battery::worker() {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
   thread_timer_ = [this] {
     dp.emit();
     thread_timer_.sleep_for(interval_);
@@ -248,6 +312,82 @@ waybar::modules::Battery::getInfos() {
     // spdlog::info("{} {} {} {}", capacity,time,status,rate);
     return {capacity, time / 60.0, status, rate, 0, 0.0F};
 
+#elif defined(__NetBSD__)
+    //Need: [capacity, time_remaining, status,      power, cycles,   health]
+    //      [uint8_t,  float,          std::string, float, uint16_t, float ]
+    prop_array_t bat;
+    prop_object_iterator_t iter;
+    prop_dictionary_t id;
+    prop_string_t desc;
+    int32_t cur_charge = 0;
+    int32_t max_charge = 0;
+    int32_t last_max_charge = 0;
+    int32_t charge_rate = 0;
+    int32_t discharge_rate = 0;
+    std::string status;
+    int32_t capacity;
+    float time_remaining;
+    float power;
+
+    if ((bat = get_device("acpibat0")) == nullptr) {
+        throw std::runtime_error("get acpibat0 device info failed");
+    }
+    if ((iter = prop_array_iterator(bat)) == nullptr) {
+        prop_object_release(bat);
+        throw std::runtime_error("prop_array_iterator failed");
+    }
+    while ((id = (prop_dictionary_t)prop_object_iterator_next(iter)) != nullptr) {
+        desc = (prop_string_t)prop_dictionary_get(id, "description");
+        if (desc == nullptr) continue;
+        if (prop_string_equals_string(desc, "charge")) {
+            cur_charge = handle_stat(id, "cur-value");
+            max_charge = handle_stat(id, "max-value");
+        } else if (prop_string_equals_string(desc, "last full cap")) {
+            if (stat_is_valid(id)) last_max_charge = handle_stat(id, "cur-value");
+        } else if (prop_string_equals_string(desc, "charge rate")) {
+            if (stat_is_valid(id)) charge_rate = handle_stat(id, "cur-value");
+        } else if (prop_string_equals_string(desc, "discharge rate")) {
+            if (stat_is_valid(id)) discharge_rate = handle_stat(id, "cur-value");
+        }
+    }
+    prop_object_iterator_release(iter);
+    prop_object_release(bat);
+
+    spdlog::info("{} {} {} {}", max_charge,cur_charge,charge_rate,discharge_rate);
+
+    if (max_charge <= 0) max_charge = last_max_charge;
+    if (charge_rate == 0 && (discharge_rate == 0 || discharge_rate == -1000)) {
+        time_remaining = 0.0;
+        power = 0.0;
+    } else {
+        if (charge_rate) {
+            time_remaining = -(float)(max_charge - cur_charge) / (float)charge_rate;
+            power = charge_rate;
+        } else {
+            time_remaining = -(float)cur_charge / (float)discharge_rate;
+            power = discharge_rate;
+        }
+    }
+
+    capacity = (cur_charge * 100) / max_charge;
+    // Handle full-at
+    if (config_["full-at"].isUInt()) {
+        auto full_at = config_["full-at"].asUInt();
+        if (full_at < 100) {
+            capacity = 100.f * capacity / full_at;
+        }
+    }
+    if (capacity > 100.f) {
+        // This can happen when the battery is calibrating and goes above 100%
+        // Handle it gracefully by clamping at 100%
+        capacity = 100.f;
+    }
+
+    status = getAdapterStatus(capacity);
+
+    spdlog::info("{} {} {} {}", capacity,time_remaining,status,power);
+    return {capacity, time_remaining, status, power, 0, 0.0F};
+
 #elif defined(__linux__)
     uint32_t total_power = 0;  // μW
     bool total_power_exists = false;
@@ -639,6 +779,38 @@ const std::string waybar::modules::Batte
   bool online = state == 2;
   std::string status{"Unknown"};  // TODO: add status in FreeBSD
   {
+#elif defined(__NetBSD__)
+  prop_array_t ac;
+  prop_object_iterator_t iter;
+  prop_dictionary_t id;
+  prop_string_t desc;
+  std::string status;
+  bool online = false;
+
+  if ((ac = get_device("acpiacad0")) == nullptr) {
+    status = "Unknown";
+  } else {
+    if ((iter = prop_array_iterator(ac)) == nullptr){
+      prop_object_release(ac);
+      throw std::runtime_error("prop_array_iterator failed");
+    }
+    while ((id = (prop_dictionary_t)prop_object_iterator_next(iter)) != nullptr) {
+      desc = (prop_string_t)prop_dictionary_get(id, "description");
+        if (desc == nullptr) continue;
+        if (!prop_string_equals_string(desc, "connected")) continue;
+        // Unknown > Full > Not charging > Discharging > Charging
+        if (handle_stat(id, "cur-value") != 0) {
+          status = "Charging";
+          online = true;
+        } else {
+          status = "Discharging";
+        }
+        break;
+    }
+    prop_object_iterator_release(iter);
+    prop_object_release(ac);
+  }
+  {
 #else
   if (!adapter_.empty()) {
     bool online;
