# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:53 jlam Exp $
#

DISTNAME=	flwm-0.25
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

DEPENDS+=	fltk-*:../../x11/fltk

USE_X11BASE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL"
CPPFLAGS+=	-I${X11PREFIX}/include

.include "../../mk/bsd.pkg.mk"
