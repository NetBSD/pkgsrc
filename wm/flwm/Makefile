# $NetBSD: Makefile,v 1.7 2001/10/23 13:15:05 jlam Exp $
#

DISTNAME=	flwm-1.00
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

.include "../../mk/x11.buildlink.mk"
.include "../../x11/fltk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
