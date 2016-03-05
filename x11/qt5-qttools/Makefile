# $NetBSD: Makefile,v 1.22 2016/03/05 11:28:01 jperkin Exp $

DISTNAME=	qttools-opensource-src-${QTVERSION}
PKGNAME=	qt5-qttools-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 tools

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

QTPKGCONFIGPC=		Qt5CLucene.pc Qt5DesignerComponents.pc Qt5UiTools.pc \
			Qt5Designer.pc Qt5Help.pc

post-install:
.for i in ${QTPKGCONFIGPC}
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
