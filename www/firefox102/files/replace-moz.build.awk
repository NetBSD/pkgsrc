/^if CONFIG\[\"OS_TARGET\"\] == \"Android\":/{
	flag = 1;
	print $0;
	next;
}
/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\":/{
	flag = 0;
	sub(/^if CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\":");
	print $0;
	next;
}
{
	if (flag != 1) {
		sub(/^    DEFINES\[\"WEBRTC_LINUX\"\] = True/, "    if CONFIG\[\"OS_TARGET\"\] == \"Linux\":\n        DEFINES\[\"WEBRTC_LINUX\"\] = True\n    else:\n        DEFINES\[\"WEBRTC_BSD\"\] = True");
		sub(/^if not CONFIG\[\"MOZ_DEBUG\"\] and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if not CONFIG[\"MOZ_DEBUG\"] and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"MOZ_DEBUG\"\] == \"1\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"MOZ_DEBUG\"] == \"1\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"CPU_ARCH\"\] == \"aarch64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"CPU_ARCH\"] == \"aarch64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"CPU_ARCH\"\] == \"x86\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"CPU_ARCH\"] == \"x86\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
		sub(/^if CONFIG\[\"CPU_ARCH\"\] == \"x86_64\" and CONFIG\[\"OS_TARGET\"\] == \"Linux\":/, "if CONFIG[\"CPU_ARCH\"] == \"x86_64\" and (CONFIG[\"OS_TARGET\"] == \"Linux\" or CONFIG[\"OS_TARGET\"] == \"NetBSD\" or CONFIG[\"OS_TARGET\"] == \"OpenBSD\" or CONFIG[\"OS_TARGET\"] == \"FreeBSD\"):");
	}
	print $0;
}
