# $NetBSD: Makefile,v 1.1 2015/06/04 19:26:55 youri Exp $

DISTNAME=	2bwm-20150526
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=venam/}
GITHUB_PROJECT=	2bwm
GITHUB_TAG=	dfb0cd1b77ce15e52e3fb9dd4eea653b0959e799

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://github.com/venam/2bwm
COMMENT=	Fast floating WM written over the XCB library and derived from mcwm
LICENSE=	isc

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
