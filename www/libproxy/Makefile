# $NetBSD: Makefile,v 1.33 2020/03/27 08:54:47 nia Exp $

DISTNAME=	libproxy-0.4.15
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GITHUB:=libproxy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libproxy.github.io/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++03
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DWITH_PERL:BOOL=OFF
CMAKE_ARGS+=	-DWITH_PYTHON2:BOOL=OFF
CMAKE_ARGS+=	-DWITH_PYTHON3:BOOL=OFF
CMAKE_ARGS+=	-DWITH_KDE:BOOL=OFF

# Need socket libraries on SunOS for both the shared library and test programs.
CMAKE_ARGS.SunOS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-lnsl -lsocket -L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
CMAKE_ARGS.SunOS+=	-DCMAKE_SHARED_LINKER_FLAGS:STRING="-lnsl -lsocket -L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib"

PKGCONFIG_OVERRIDE+=	bindings/csharp/libproxy-sharp-1.0.pc.cmake
PKGCONFIG_OVERRIDE+=	libproxy/libproxy-1.0.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
