# $NetBSD: Makefile,v 1.6 2012/10/08 13:04:20 asau Exp $
#

DISTNAME=	libical-0.44
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeassociation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeassociation.sourceforge.net/
COMMENT=	Reference implementation of the iCalendar data type and format

USE_TOOLS+=	perl
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-builtintz

PKGCONFIG_OVERRIDE+=	libical.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# zone.tab file in /usr/share/zoneinfo
DEPENDS+= zonetab-[0-9]*:../../time/zonetab
.endif

# C++ is only needed for test
#USE_LANGUAGES=	c c++
#TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
