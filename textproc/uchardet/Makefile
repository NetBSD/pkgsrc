# $NetBSD: Makefile,v 1.2 2022/04/25 23:16:50 tnn Exp $

DISTNAME=	uchardet-0.0.7
CATEGORIES=	textproc
MASTER_SITES=	https://www.freedesktop.org/software/uchardet/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/uchardet/
COMMENT=	Encoding detector library ported from Mozilla
LICENSE=	mpl-1.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	test

# C++11
GCC_REQD+=	4.7

PKGCONFIG_OVERRIDE+=	uchardet.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/version.script

.include "../../mk/bsd.pkg.mk"
