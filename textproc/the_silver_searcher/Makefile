# $NetBSD: Makefile,v 1.3 2013/10/20 22:14:21 wiz Exp $

DISTNAME=	0.17
PKGNAME=	the_silver_searcher-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/ggreer/the_silver_searcher/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggreer/the_silver_searcher
COMMENT=	Attempt to improve on ack, which itself is better than grep
LICENSE=	apache-2.0

WRKSRC= ${WRKDIR}/${PKGNAME_NOREV}

DIST_SUBDIR=	the_silver_searcher

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	LZMA_CFLAGS=-I${BUILDLINK_PREFIX.xz}/include
CONFIGURE_ARGS+=	LZMA_LIBS="-L${BUILDLINK_PREFIX.xz}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.xz}/lib -llzma"
USE_TOOLS+=	aclocal autoheader autoconf automake autoreconf pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/pcre/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
