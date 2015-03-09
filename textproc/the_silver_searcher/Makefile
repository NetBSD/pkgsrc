# $NetBSD: Makefile,v 1.8 2015/03/09 23:36:20 tnn Exp $

DISTNAME=	the_silver_searcher-0.29.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggreer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggreer/the_silver_searcher
COMMENT=	Attempt to improve on ack, which itself is better than grep
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	LZMA_CFLAGS=-I${BUILDLINK_PREFIX.xz}/include
CONFIGURE_ARGS+=	LZMA_LIBS="-L${BUILDLINK_PREFIX.xz}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.xz}/lib -llzma"
USE_TOOLS+=	aclocal autoheader autoconf automake autoreconf pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/pcre/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
