# $NetBSD: Makefile,v 1.18 2011/11/01 06:02:40 sbd Exp $

DISTNAME=	ptimetracker-1.7.3
PKGREVISION=	8
CATEGORIES=	time kde
MASTER_SITES=	http://www.eggtart.plus.com/ptt/prog/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.eggtart.plus.com/ptt/
COMMENT=	Keep track of the time spent on projects

PKG_DESTDIR_SUPPORT=	user-destdir

# USE_GNOME=	gnomehack gnomeprefix libgtkhtml libgnomeui
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile ptt.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ptimetracker ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ptimetracker.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
