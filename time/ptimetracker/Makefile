# $NetBSD: Makefile,v 1.11 2006/05/22 22:04:15 wiz Exp $

DISTNAME=	ptimetracker-1.7.3
PKGREVISION=	3
CATEGORIES=	time kde
MASTER_SITES=	http://www.eggtart.plus.com/ptt/prog/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.eggtart.plus.com/ptt/
COMMENT=	Keep track of the time spent on projects

# USE_GNOME=	gnomehack gnomeprefix libgtkhtml libgnomeui
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin man/man1

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile ptt.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ptimetracker ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ptimetracker.1 ${PREFIX}/man/man1/

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
