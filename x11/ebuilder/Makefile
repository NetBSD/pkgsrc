# $NetBSD: Makefile,v 1.6 2000/10/19 07:57:17 skrll Exp $
#

DISTNAME=	ebuilder-0.56d
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	http://web.inter.nl.net/users/eavdmeer/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://web.inter.nl.net/users/eavdmeer/index.html

DEPENDS+=	qt2-libs-*:../../x11/qt2-libs
DEPENDS+=	png-*:../../graphics/png

USE_X11=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

EVAL_PREFIX+=	QT2DIR=qt2
MAKE_ENV=	QTDIR=${QT2DIR}/qt2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
