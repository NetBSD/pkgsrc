# $NetBSD: Makefile,v 1.14 2020/06/02 09:59:45 nia Exp $

DISTNAME=	uriparser-0.9.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=uriparser/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uriparser.github.io/
COMMENT=	URI parsing library
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_FEATURES=		snprintf
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE+=	liburiparser.pc.in
TEST_TARGET=		test

CMAKE_ARGS+=		-DURIPARSER_BUILD_DOCS=OFF

# reallocarray etc
CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
