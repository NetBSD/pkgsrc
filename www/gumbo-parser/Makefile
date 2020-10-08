# $NetBSD: Makefile,v 1.1 2020/10/08 22:36:20 leot Exp $

DISTNAME=	gumbo-parser-0.10.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/gumbo-parser/
COMMENT=	HTML5 parsing library in pure C99
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake

PKGCONFIG_OVERRIDE=	gumbo.pc.in

USE_LANGUAGES=	c99 c++

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
