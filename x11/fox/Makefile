# $NetBSD: Makefile,v 1.20 2004/10/03 00:18:29 tv Exp $
#

DISTNAME=	fox-1.0.43
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://www.fox-toolkit.org/ftp/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.fox-toolkit.org/
COMMENT=	Fast and extensive C++ GUI toolkit

USE_BUILDLINK3=	yes
USE_X11=	# defined
USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined

CONFIGURE_ARGS+=	--with-opengl=mesa
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-shm=yes
CONFIGURE_ARGS+=	--enable-release

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
