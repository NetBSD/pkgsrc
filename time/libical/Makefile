# $NetBSD: Makefile,v 1.17 2018/08/22 09:47:14 wiz Exp $
#

DISTNAME=	libical-3.0.3
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=libical/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libical/libical/
COMMENT=	Reference implementation of the iCalendar data type and format
LICENSE=	gnu-lgpl-v2.1 OR mpl-2.0

USE_TOOLS+=	perl pkg-config
USE_CMAKE=	yes
CMAKE_ARGS+= -DUSE_BUILTIN_TZDATA=false
CMAKE_ARGS+= -DICAL_BUILD_DOCS=false
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	libical.pc.in src/libical-glib/libical-glib.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
# zone.tab file in /usr/share/zoneinfo
DEPENDS+= zonetab-[0-9]*:../../time/zonetab
.endif

# C++ is only needed for test
USE_LANGUAGES=	c c++
#TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
