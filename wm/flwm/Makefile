# $NetBSD: Makefile,v 1.25 2011/01/13 13:39:32 wiz Exp $
#

DISTNAME=	flwm-1.02
PKGREVISION=	2
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
