# $NetBSD: Makefile,v 1.18 2005/12/05 20:51:09 rillig Exp $
#

DISTNAME=	flwm-1.00
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager


GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=	-DFLTK_1_0_COMPAT

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
