# $NetBSD: hacks.mk,v 1.5 2013/05/23 13:25:30 ryoon Exp $

# workround for link of seamonkey-bin etc.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/seamonkey

.include "../../www/firefox/hacks.mk"
