# $NetBSD: hacks.mk,v 1.4 2012/06/14 11:27:34 ryoon Exp $

# workround for link of thunderbird-bin etc.
LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib/seamonkey

.include "../../devel/xulrunner/hacks.mk"
