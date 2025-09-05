# $NetBSD: Makefile,v 1.6 2025/09/05 14:56:05 ktnb Exp $

VERSION=	0.13.2
PKGNAME=	gumbo-parser-${VERSION}
DISTNAME=	${VERSION}
CATEGORIES=	www
MASTER_SITES=	https://codeberg.org/grisha/gumbo-parser/archive/
DIST_SUBDIR=	gumbo-parser

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/grisha/gumbo-parser/
COMMENT=	HTML5 parsing library in pure C99
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/gumbo-parser

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake cmake pkg-config

PKGCONFIG_OVERRIDE=	gumbo.pc.in

USE_LANGUAGES=	c c++

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/meson/build.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
