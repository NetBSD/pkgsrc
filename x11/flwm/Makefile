# $NetBSD: Makefile,v 1.1.1.1 2000/08/04 03:57:33 jlam Exp $
#

DISTNAME=	flwm-0.25
CATEGORIES=	x11
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://flwm.sourceforge.net/

DEPENDS+=	fltk-*:../../x11/fltk

USE_X11BASE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	X_LIBS="-lGL" CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${X11PREFIX}/include

.include "../../mk/bsd.pkg.mk"
