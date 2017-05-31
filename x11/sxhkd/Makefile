# $NetBSD: Makefile,v 1.2 2017/05/31 05:15:47 maya Exp $

DISTNAME=		sxhkd-0.5.7
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
