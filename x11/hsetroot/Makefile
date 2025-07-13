# $NetBSD: Makefile,v 1.35 2025/07/13 15:13:34 vins Exp $

DISTNAME=	hsetroot-1.0.5
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=himdel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/himdel/hsetroot
COMMENT=	Allows you to compose wallpapers for X
LICENSE=	gnu-gpl-v2

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

MAKE_FILE=	make.local
MAKE_FLAGS+=	CC=${CC:Q} PREFIX=${PREFIX}

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
