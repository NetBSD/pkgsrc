# $NetBSD: Makefile,v 1.13 2004/04/13 09:33:51 xtraeme Exp $
#

DISTNAME=	flwm-1.00
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

USE_BUILDLINK3=	yes
USE_X11=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=	-DFLTK_1_0_COMPAT

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
