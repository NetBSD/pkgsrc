# $NetBSD: Makefile,v 1.11 2003/07/17 22:55:11 grant Exp $
#

DISTNAME=	flwm-1.00
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

USE_BUILDLINK2=	# defined
USE_X11BASE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"

.include "../../x11/fltk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
