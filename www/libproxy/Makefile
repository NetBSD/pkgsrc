# $NetBSD: Makefile,v 1.36 2023/01/24 18:36:35 wiz Exp $

DISTNAME=	libproxy-0.4.15
PKGREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=libproxy/}

PATCH_SITES=		https://github.com/libproxy/libproxy/commit/
PATCHFILES=		a83dae404feac517695c23ff43ce1e116e2bfbe0.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libproxy.github.io/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c99 c++03
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

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
