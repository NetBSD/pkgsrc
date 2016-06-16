# $NetBSD: hacks.mk,v 1.5 2016/06/16 12:08:21 ryoon Exp $

.if !defined(FIREFOX_HACKS_MK)
FIREFOX_HACKS_MK=	defined

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-return-type-c-linkage
.endif

.endif	# FIREFOX_HACKS_MK
