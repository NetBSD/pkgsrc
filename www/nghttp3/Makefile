# $NetBSD: Makefile,v 1.18 2024/06/14 15:24:14 adam Exp $

DISTNAME=	nghttp3-1.4.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/nghttp3
COMMENT=	Implementation of RFC 9114 HTTP/3 mapping over QUIC and RFC 9204 QPACK
LICENSE=	mit

USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
