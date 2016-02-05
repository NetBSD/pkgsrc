# $NetBSD: Makefile,v 1.2 2016/02/05 17:47:54 adam Exp $

DISTNAME=	libsass-3.3.3
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sass/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sass-lang.com/libsass/
COMMENT=	C/C++ port of the Sass CSS precompiler
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoheader autoconf automake gmake
GNU_CONFIGURE=		yes
MAKE_FILE=		GNUmakefile

pre-configure:
	set -e; cd ${WRKSRC}; libtoolize -c -f; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
