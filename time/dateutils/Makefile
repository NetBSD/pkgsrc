# $NetBSD: Makefile,v 1.2 2013/10/31 08:32:55 wiz Exp $

DISTNAME=	dateutils-0.2.6
CATEGORIES=	time
MASTER_SITES=	http://cdn.bitbucket.org/hroptatyr/dateutils/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fresse.org/dateutils/
COMMENT=	Command line tools for working with dates
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdut.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
