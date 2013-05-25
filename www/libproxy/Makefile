# $NetBSD: Makefile,v 1.17 2013/05/25 11:13:12 obache Exp $

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
LIBS.SunOS+=	-lnsl -lsocket
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF

PKGCONFIG_OVERRIDE+=	bindings/csharp/libproxy-sharp-1.0.pc.cmake
PKGCONFIG_OVERRIDE+=	libproxy/libproxy-1.0.pc.in

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
