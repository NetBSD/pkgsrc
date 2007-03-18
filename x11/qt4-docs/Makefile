# $NetBSD: Makefile,v 1.3 2007/03/18 17:34:41 adam Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-docs-${QTVERSION}
COMMENT=	Documentation for the QT C++ X GUI toolkit

NO_CONFIGURE=		yes
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST ${PKGDIR}/PLIST

do-install:
	cp -R ${WRKSRC}/doc ${QTPREFIX}
	cd ${PREFIX}; find qt4/doc -type f -print > ${WRKDIR}/PLIST

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
