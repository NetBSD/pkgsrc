# $NetBSD: Makefile,v 1.16 2023/11/08 13:21:11 wiz Exp $

DISTNAME=	dateutils-0.4.10
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=hroptatyr/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fresse.org/dateutils/
COMMENT=	Command line tools for working with dates
LICENSE=	modified-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf bison flex gmake makeinfo pkg-config
GNU_CONFIGURE=	yes
INFO_FILES=	yes
TEST_TARGET=	check

# For patch-m4_sxe-compiler.m4
pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/gperf/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
