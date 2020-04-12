# $NetBSD: Makefile,v 1.26 2020/04/12 08:28:08 adam Exp $

DISTNAME=	libical-3.0.7
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=libical/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libical/libical/
COMMENT=	Reference implementation of the iCalendar data type and format
LICENSE=	gnu-lgpl-v2.1 OR mpl-2.0

USE_TOOLS+=	perl pkg-config
USE_CMAKE=	yes

CMAKE_ARGS+= 	-DUSE_BUILTIN_TZDATA=OFF
CMAKE_ARGS+=	-DICAL_BUILD_DOCS=OFF
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_BDB=ON

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/tclsh
REPLACE.perl.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.perl=

PKGCONFIG_OVERRIDE+=	libical.pc.in
PKGCONFIG_OVERRIDE+=	src/libical-glib/libical-glib.pc.in

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
