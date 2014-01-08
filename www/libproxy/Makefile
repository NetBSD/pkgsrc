# $NetBSD: Makefile,v 1.21 2014/01/08 09:57:30 jperkin Exp $

DISTNAME=	libproxy-0.4.11
CATEGORIES=	www gnome
MASTER_SITES=	http://libproxy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libproxy/
COMMENT=	Library that provides automatic proxy configuration management
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c99 c++
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF

.include "../../mk/bsd.fast.prefs.mk"

.if (${OPSYS} == "SunOS")
# add libraries needed for Solaris, and add stuff cmake would add it on its own
CMAKE_ARGS+=		-DCMAKE_EXE_LINKER_FLAGS:STRING="-lnsl -lsocket ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-as-needed
.endif

PKGCONFIG_OVERRIDE+=	bindings/csharp/libproxy-sharp-1.0.pc.cmake
PKGCONFIG_OVERRIDE+=	libproxy/libproxy-1.0.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
