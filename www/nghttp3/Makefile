# $NetBSD: Makefile,v 1.1 2022/12/03 16:01:02 adam Exp $

DISTNAME=	nghttp3-0.7.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ngtcp2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ngtcp2/nghttp3
COMMENT=	Implementation of RFC 9114 HTTP/3 mapping over QUIC and RFC 9204 QPACK
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
