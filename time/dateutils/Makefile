# $NetBSD: Makefile,v 1.1 2013/10/21 15:05:05 wiz Exp $

DISTNAME=	dateutils-0.2.5
CATEGORIES=	time
MASTER_SITES=	http://cdn.bitbucket.org/hroptatyr/dateutils/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fresse.org/dateutils/
COMMENT=	Command line tools for working with dates
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdut.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
