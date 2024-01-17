# $NetBSD: Makefile,v 1.2 2024/01/17 23:49:50 gdt Exp $

VERSION=	0.12.1
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
USE_TOOLS+=	aclocal autoconf automake

PKGCONFIG_OVERRIDE=	gumbo.pc.in

USE_LANGUAGES=	c99 c++

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
