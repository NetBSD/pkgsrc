# $NetBSD: Makefile,v 1.27 2013/01/26 21:38:59 adam Exp $
#

DISTNAME=	flwm-1.02
PKGREVISION=	3
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=	-DFLTK_1_0_COMPAT

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
