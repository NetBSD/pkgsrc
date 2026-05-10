# $NetBSD: Makefile,v 1.62 2026/05/10 15:28:14 gutteridge Exp $

DISTNAME=	libical-3.0.20
PKGREVISION=	4
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=libical/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libical/libical
COMMENT=	Reference implementation of the iCalendar data type and format (v3)
LICENSE=	gnu-lgpl-v2.1 OR mpl-2.0

CONFLICTS=	libical>=4

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
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
