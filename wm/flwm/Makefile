# $NetBSD: Makefile,v 1.8.2.1 2002/06/30 06:24:27 jlam Exp $
#

DISTNAME=	flwm-1.00
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

USE_BUILDLINK2=	# defined
USE_X11BASE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"

.include "../../x11/fltk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
