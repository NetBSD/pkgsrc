# $NetBSD: Makefile,v 1.28 2005/08/20 10:50:52 grant Exp $

DISTNAME=	fox-1.4.17
CATEGORIES=	x11
MASTER_SITES=	http://www.fox-toolkit.org/ftp/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.fox-toolkit.org/
COMMENT=	Fast and extensive C++ GUI toolkit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--with-opengl
CONFIGURE_ARGS+=	--with-shm
CONFIGURE_ARGS+=	--with-x

.include "../../mk/bsd.prefs.mk"

# NetBSD < 3.0 does not have getpwnam_r() getpwuin_r()
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[1-2]*)
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
