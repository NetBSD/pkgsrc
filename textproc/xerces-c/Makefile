# $NetBSD: Makefile,v 1.59 2025/04/17 21:52:39 wiz Exp $

DISTNAME=	xerces-c-3.3.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xerces.apache.org/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_ICU=true
PKGCONFIG_OVERRIDE=	xerces-c.pc.in

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src
TEST_TARGET=	test

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		iconv gnuiconv macunicode

.if ${OPSYS} == "Darwin"
PLIST.macunicode=	yes
.elif ${OPSYS} == "SunOS"
PLIST.iconv=		yes
CMAKE_CONFIGURE_ARGS+=	-DXERCES_USE_TRANSCODER_GNUICONV=false
CMAKE_CONFIGURE_ARGS+=	-DXERCES_USE_TRANSCODER_ICONV=true
.else
PLIST.gnuiconv=		yes
.include "../../converters/libiconv/buildlink3.mk"
LDFLAGS+=		-liconv
.endif

.include "../../devel/cmake/build.mk"
# curl as net accessor is the most compatible option across platforms.
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
