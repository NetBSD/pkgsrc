# $NetBSD: Makefile,v 1.8 2017/11/17 11:36:30 adam Exp $

DISTNAME=	sassc-3.4.7
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
