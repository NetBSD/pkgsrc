# $NetBSD: Makefile,v 1.12 2014/12/27 22:57:13 wiz Exp $

PKGNAME=	qt5-qttools-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 tools

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS=		qttools
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

QTPKGCONFIGPC=		Qt5CLucene.pc Qt5DesignerComponents.pc Qt5UiTools.pc \
			Qt5Designer.pc Qt5Help.pc

post-install:
.for i in ${QTPKGCONFIGPC}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
