# $NetBSD: Makefile,v 1.38 2023/02/20 09:55:17 ryoon Exp $

DISTNAME=	libproxy-0.4.18
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=libproxy/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libproxy.github.io/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DWITH_PERL:BOOL=OFF
CMAKE_ARGS+=	-DWITH_PYTHON2:BOOL=OFF
CMAKE_ARGS+=	-DWITH_PYTHON3:BOOL=OFF
CMAKE_ARGS+=	-DWITH_KDE:BOOL=OFF

# Need socket libraries on SunOS for both the shared library and test programs.
CMAKE_ARGS.SunOS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-lnsl -lsocket -L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
CMAKE_ARGS.SunOS+=	-DCMAKE_SHARED_LINKER_FLAGS:STRING="-lnsl -lsocket -L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-as-needed

PKGCONFIG_OVERRIDE+=	bindings/csharp/libproxy-sharp-1.0.pc.cmake
PKGCONFIG_OVERRIDE+=	libproxy/libproxy-1.0.pc.in

TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
