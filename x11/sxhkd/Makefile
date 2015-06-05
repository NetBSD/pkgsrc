# $NetBSD: Makefile,v 1.1 2015/06/05 22:45:07 youri Exp $

DISTNAME=		sxhkd-0.5.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=baskerville/}
GITHUB_TAG=		${PKGVERSION}

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		https://github.com/baskerville/sxhkd
COMMENT=		Simple X hotkey daemon
LICENSE=		2-clause-bsd

USE_TOOLS+=		gmake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile=	-e 's,share/man,${PKGMANDIR},g'

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
