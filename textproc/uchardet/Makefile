# $NetBSD: Makefile,v 1.3 2023/07/18 18:47:53 nia Exp $

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

USE_CXX_FEATURES+=	c++11

PKGCONFIG_OVERRIDE+=	uchardet.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/version.script

.include "../../mk/bsd.pkg.mk"
