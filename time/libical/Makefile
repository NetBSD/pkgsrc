# $NetBSD: Makefile,v 1.50 2024/08/19 17:30:45 wiz Exp $

DISTNAME=	libical-3.0.18
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=libical/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libical/libical
COMMENT=	Reference implementation of the iCalendar data type and format
LICENSE=	gnu-lgpl-v2.1 OR mpl-2.0

USE_TOOLS+=	perl pkg-config

CMAKE_CONFIGURE_ARGS+=	-DUSE_BUILTIN_TZDATA=OFF
CMAKE_CONFIGURE_ARGS+=	-DICAL_BUILD_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_BerkeleyDB=ON

PKGCONFIG_OVERRIDE+=	libical.pc.in
PKGCONFIG_OVERRIDE+=	src/libical-glib/libical-glib.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# zone.tab file in /usr/share/zoneinfo
DEPENDS+=	zonetab-[0-9]*:../../time/zonetab
.endif

# C++ is only needed for test
USE_LANGUAGES=	c c++
#TEST_TARGET=	check

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
