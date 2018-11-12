# $NetBSD: Makefile,v 1.46 2018/11/12 03:51:36 ryoon Exp $

DISTNAME=	qttools-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qttools-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 tools

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

MAKE_ENV+=		LLVM_INSTALL_DIR=${BUILDLINK_PREFIX.clang}
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

QTPKGCONFIGPC=		Qt5Designer.pc Qt5Help.pc Qt5UiTools.pc

post-install:
.for i in ${QTPKGCONFIGPC}
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../lang/clang/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
