# $NetBSD: Makefile,v 1.4 2023/07/11 05:37:06 nia Exp $

DISTNAME=	2bwm-0.3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=venam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/venam/2bwm
COMMENT=	Fast floating WM written over the XCB library and derived from mcwm
LICENSE=	isc

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99

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
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
