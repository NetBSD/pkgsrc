# $NetBSD: Makefile,v 1.8 2023/07/06 07:28:20 nia Exp $

DISTNAME=	nghttp3-0.12.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/nghttp3
COMMENT=	Implementation of RFC 9114 HTTP/3 mapping over QUIC and RFC 9204 QPACK
LICENSE=	mit

USE_LANGUAGES=	c c++

# C++17
GCC_REQD+=	7

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
