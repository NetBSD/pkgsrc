# $NetBSD: Makefile,v 1.5 2000/07/15 20:39:25 agc Exp $
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

EVAL_PREFIX+=	QT2DIR=qt2
MAKE_ENV=	QTDIR=${QT2DIR}/qt2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
