# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:47 tv Exp $
#

DISTNAME=	flwm-1.00
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

USE_X11=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=	-DFLTK_1_0_COMPAT

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
