# $NetBSD: Makefile,v 1.13 2003/08/29 10:16:11 xtraeme Exp $
#

DISTNAME=	fox-1.0.43
CATEGORIES=	x11
MASTER_SITES=	http://www.fox-toolkit.org/ftp/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.fox-toolkit.org/
COMMENT=	Fast and extensive C++ GUI toolkit

USE_BUILDLINK2=	# defined
USE_X11=	# defined
USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined

CONFIGURE_ARGS+=	--with-opengl=mesa 
CONFIGURE_ARGS+=	--with-x
CONFIFURE_ARGS+=	--with-shm=yes
CONFIGURE_ARGS+=	--enable-release

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
