# $NetBSD: Makefile,v 1.4 2001/06/30 10:15:06 zuntum Exp $
#

DISTNAME=	flwm-0.25
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"
CPPFLAGS+=	-I${X11PREFIX}/include

.include "../../x11/fltk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
