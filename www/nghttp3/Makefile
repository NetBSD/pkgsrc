# $NetBSD: Makefile,v 1.32 2026/06/28 08:14:46 adam Exp $

DISTNAME=	nghttp3-1.17.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/nghttp3
COMMENT=	Implementation of RFC 9114 HTTP/3 mapping over QUIC and RFC 9204 QPACK
LICENSE=	mit

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
