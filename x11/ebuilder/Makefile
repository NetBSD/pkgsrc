# $NetBSD: Makefile,v 1.9 2001/03/04 09:06:20 tron Exp $
#

DISTNAME=	ebuilder-0.56d
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	x11 devel
MASTER_SITES=	http://web.inter.nl.net/users/eavdmeer/src/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://web.inter.nl.net/users/eavdmeer/index.html
COMMENT=	GUI builder for the Qt library

DEPENDS+=	qt2-libs-*:../../x11/qt2-libs
DEPENDS+=	png>1.0.9:../../graphics/png

USE_X11=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

EVAL_PREFIX+=	QT2DIR=qt2-libs
MAKE_ENV=	QTDIR=${QT2DIR}/qt2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ebuilder ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
