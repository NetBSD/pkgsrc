# $NetBSD: Makefile,v 1.1 2026/04/15 08:41:18 kikadf Exp $

DISTNAME=	lswt-2.0.0
CATEGORIES=	wayland
MASTER_SITES=	https://git.sr.ht/~leon_plickat/lswt/archive/
DIST_SUBDIR=	lswt
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://sr.ht/~leon_plickat/lswt/
COMMENT=	List Wayland toplevels
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake #pkg-config
BUILD_TARGET=	lswt
WRKSRC=		${WRKDIR}/lswt-v${PKGVERSION_NOREV}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	Makefile
SUBST_VARS.path+=	PREFIX PKGMANDIR

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
