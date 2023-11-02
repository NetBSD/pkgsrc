# $NetBSD: Makefile,v 1.29 2023/11/02 12:15:02 nros Exp $

DISTNAME=	logswan-2.1.14
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

CMAKE_CONFIGURE_ARGS+=	-DGEOIP2DIR=${PREFIX}/share/dbip

TEST_TARGET=	test

.include "../../devel/cmake/build.mk"

.include "../../textproc/jansson/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
