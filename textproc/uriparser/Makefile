# $NetBSD: Makefile,v 1.24.4.1 2026/11/11 13:21:54 maya Exp $

DISTNAME=	uriparser-1.0.3
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

CMAKE_CONFIGURE_ARGS+=		-DURIPARSER_BUILD_DOCS=OFF

# reallocarray etc
CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE
CFLAGS.SunOS+=		-D__EXTENSIONS__

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
