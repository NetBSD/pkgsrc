# $NetBSD: Makefile,v 1.3 2000/07/11 14:53:46 agc Exp $
#

DISTNAME=	ebuilder-0.56c
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	http://www.phys.uu.nl/~meer/Ebuilder/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.phys.uu.nl/~meer/Ebuilder/

DEPENDS+=	qt2-*:../../x11/qt
DEPENDS+=	png-*:../../graphics/png

USE_X11=	yes
MAKE_ENV=	QTDIR=`${MAKE} show-qt2-prefix`/qt2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
