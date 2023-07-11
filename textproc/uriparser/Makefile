# $NetBSD: Makefile,v 1.17 2023/07/11 05:55:10 nia Exp $

DISTNAME=	uriparser-0.9.6
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
PKGCONFIG_OVERRIDE+=	liburiparser.pc.in

CMAKE_ARGS+=		-DURIPARSER_BUILD_DOCS=OFF

# reallocarray etc
CFLAGS.NetBSD+=		-D_OPENBSD_SOURCE

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
