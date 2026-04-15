# $NetBSD: Makefile,v 1.1 2026/04/15 08:18:02 kikadf Exp $

DISTNAME=	wlopm-1.0.0
CATEGORIES=	wayland
MASTER_SITES=	https://git.sr.ht/~leon_plickat/wlopm/archive/
DIST_SUBDIR=	wlopm
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://sr.ht/~leon_plickat/wlopm/
COMMENT=	Wayland output power management
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
BUILD_TARGET=	wlopm
USE_TOOLS+=	gmake
MAKE_FLAGS+=	SCANNER=${TOOLBASE:Q}/bin/wayland-scanner
TOOL_DEPENDS+=	wayland-[0-9]*:../../devel/wayland
WRKSRC=		${WRKDIR}/wlopm-v${PKGVERSION_NOREV}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	Makefile
SUBST_VARS.path+=	PREFIX PKGMANDIR

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
