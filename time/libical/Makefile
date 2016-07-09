# $NetBSD: Makefile,v 1.14 2016/07/09 06:39:08 wiz Exp $
#

DISTNAME=	libical-1.0
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeassociation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeassociation.sourceforge.net/
COMMENT=	Reference implementation of the iCalendar data type and format
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.0

USE_TOOLS+=	perl
USE_CMAKE=	yes
CMAKE_ARGS+= -DUSE_BUILTIN_TZDATA=false
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	libical.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# zone.tab file in /usr/share/zoneinfo
DEPENDS+= zonetab-[0-9]*:../../time/zonetab
.endif

# C++ is only needed for test
USE_LANGUAGES=	c c++
#TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
