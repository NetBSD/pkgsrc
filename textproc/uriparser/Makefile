# $NetBSD: Makefile,v 1.18 2024/05/06 05:49:28 wiz Exp $

DISTNAME=	uriparser-0.9.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=uriparser/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uriparser.github.io/
COMMENT=	URI parsing library
LICENSE=	modified-bsd

USE_FEATURES=		snprintf
PKGCONFIG_OVERRIDE+=	liburiparser.pc.in

CMAKE_ARGS+=		-DURIPARSER_BUILD_DOCS=OFF

# reallocarray etc
CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
