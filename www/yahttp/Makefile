# $NetBSD: Makefile,v 1.3 2015/04/17 15:53:16 adam Exp $

DISTNAME=	yahttp-0.1.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=cmouse/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=cmouse/yahttp/}
COMMENT=	Yet Another HTTP Library
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf autoheader automake

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
