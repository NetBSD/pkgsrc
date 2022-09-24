# $NetBSD: hacks.mk,v 1.1 2022/09/24 07:46:31 nia Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64*)
# pty.cc:(.text+0x18): undefined reference to `__aarch64_ldadd4_acq_rel'
# https://bugzilla.redhat.com/show_bug.cgi?id=1830472
PKG_HACKS+=		no-outline-atomics
CFLAGS.NetBSD+=		-march=armv8-a -mno-outline-atomics
.endif
