# $NetBSD: Makefile,v 1.1 2016/06/11 23:07:14 kamil Exp $

DISTNAME=	wmutils-core-1.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmutils/}
GITHUB_PROJECT=	core
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmutils.io/
COMMENT=	Window Manipulation Utilities
LICENSE=	isc

MAKE_FLAGS+=		PREFIX=${PREFIX}
LDFLAGS+=		${LINKER_RPATH_FLAG}${X11BASE}/lib
LDFLAGS+=		-lxcb
BUILD_MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
