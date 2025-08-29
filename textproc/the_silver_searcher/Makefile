# $NetBSD: Makefile,v 1.20 2025/08/29 12:17:31 leot Exp $

DISTNAME=	the_silver_searcher-2.2.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://geoff.greer.fm/ag/releases/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/ggreer/the_silver_searcher
COMMENT=	Attempt to improve on ack, which itself is better than grep
LICENSE=	apache-2.0

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	LZMA_CFLAGS=-I${BUILDLINK_PREFIX.xz}/include
CONFIGURE_ARGS+=	LZMA_LIBS="-L${BUILDLINK_PREFIX.xz}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.xz}/lib -llzma"
USE_TOOLS+=		pkg-config

.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
