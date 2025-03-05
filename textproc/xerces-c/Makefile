# $NetBSD: Makefile,v 1.56 2025/03/05 06:14:11 adam Exp $

DISTNAME=	xerces-c-3.3.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xerces.apache.org/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
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
CONFIGURE_ARGS+=	--enable-transcoder-iconv
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
