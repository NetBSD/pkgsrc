# $NetBSD: Makefile,v 1.41 2020/04/12 08:29:15 adam Exp $

DISTNAME=	fet-5.25.0
PKGREVISION=	32
CATEGORIES=	time
MASTER_SITES=	https://lalescu.ro/liviu/fet/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lalescu.ro/liviu/fet/
COMMENT=	Automatically schedule timetables
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bsdtar
EXTRACT_USING=		bsdtar
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/fet

# conflicts with import.h in package itself
pre-build:
	rm -f ${WRKDIR}/.buildlink/include/python*/import.h
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fet ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fet-cl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/fet.1.gz ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/man/fet-cl.1.gz ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fet

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
