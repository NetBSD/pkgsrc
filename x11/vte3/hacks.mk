# $NetBSD: hacks.mk,v 1.2 2024/05/14 09:30:38 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64*}
# pty.cc:(.text+0x18): undefined reference to `__aarch64_ldadd4_acq_rel'
# https://bugzilla.redhat.com/show_bug.cgi?id=1830472
PKG_HACKS+=		no-outline-atomics
CFLAGS.NetBSD+=		-march=armv8-a -mno-outline-atomics
.endif
