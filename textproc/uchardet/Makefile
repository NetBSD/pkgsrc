# $NetBSD: Makefile,v 1.1 2020/06/09 13:53:00 nia Exp $

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

.include "../../mk/bsd.pkg.mk"
