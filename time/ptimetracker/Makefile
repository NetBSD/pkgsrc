# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:38 jlam Exp $

DISTNAME=	ptimetracker-1.7.3
PKGREVISION=	# empty
CATEGORIES=	time kde
MASTER_SITES=	http://www.eggtart.plus.com/ptt/prog/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.eggtart.plus.com/ptt/
COMMENT=	Keep track of the time spent on projects

# USE_GNOME=	gnomehack gnomeprefix libgtkhtml libgnomeui
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin man/man1

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile ptt.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ptimetracker ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ptimetracker.1 ${PREFIX}/man/man1/

# need only qmake during build
BUILDLINK_DEPMETHOD.qt3-tools=	build

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
