# $NetBSD: hacks.mk,v 1.1 2017/04/27 01:55:57 ryoon Exp $

.if !defined(FIREFOX_HACKS_MK)
FIREFOX_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-return-type-c-linkage
.endif

.endif	# FIREFOX_HACKS_MK
