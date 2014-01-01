# $NetBSD: Makefile,v 1.2 2014/01/01 11:52:06 wiz Exp $

PKGNAME=	qt5-qttools-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 tools

.include "../../x11/qt5-qtbase/Makefile.common"

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qttools
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

QTPROG_BIN=		assistant linguist qcollectiongenerator \
			designer lrelease qhelpconverter \
			lconvert lupdate qhelpgenerator

QTPKGCONFIGPC=		Qt5CLucene.pc Qt5DesignerComponents.pc Qt5UiTools.pc \
			Qt5Designer.pc Qt5Help.pc

post-install:
.for prog in ${QTPROG_BIN}
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/${BUILD_DIRS}/bin/${prog} \
		${DESTDIR}${QTPREFIX}/bin/${prog}
.endfor
.for i in ${QTPKGCONFIGPC}
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/${i} && \
		cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
		ln -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-dbus/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
