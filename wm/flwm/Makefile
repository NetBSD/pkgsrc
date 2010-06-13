# $NetBSD: Makefile,v 1.24 2010/06/13 22:45:30 wiz Exp $
#

DISTNAME=	flwm-1.02
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://flwm.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flwm.sourceforge.net/
COMMENT=	The Fast, Light Window Manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	X_LIBS="-lGL"
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=	-DFLTK_1_0_COMPAT

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
