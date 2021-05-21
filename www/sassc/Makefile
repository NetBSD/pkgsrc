# $NetBSD: Makefile,v 1.13 2021/05/21 07:05:52 adam Exp $

DISTNAME=	sassc-3.6.2
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sass/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sass-lang.com/libsass/
COMMENT=	Wrapper around libsass
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoheader autoconf automake gmake
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile

pre-configure:
	set -e; cd ${WRKSRC}; libtoolize -c -f; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../www/libsass/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
