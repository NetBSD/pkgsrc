# $NetBSD: Makefile,v 1.27 2026/01/07 08:49:11 wiz Exp $

DISTNAME=	dateutils-0.4.11
PKGREVISION=	9
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

CFLAGS.SunOS+=	-D__EXTENSIONS__

# For patch-m4_sxe-compiler.m4
pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/gperf/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
