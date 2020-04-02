# $NetBSD: Makefile,v 1.63 2020/04/02 22:05:59 adam Exp $

DISTNAME=	qttools-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qttools-${QTVERSION}
COMMENT=	Qt5 tools

DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt5-qttools
PKG_SUPPORTED_OPTIONS+=	llvm
PKG_SUGGESTED_OPTIONS+=	llvm
PLIST_VARS+=		llvm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mllvm)
PLIST.llvm=		yes
MAKE_ENV+=		LLVM_INSTALL_DIR=${BUILDLINK_PREFIX.clang}
.include "../../lang/clang/buildlink3.mk"
.endif

.include "../../x11/qt5-qtbase/Makefile.common"

QTPKGCONFIGPC=		Qt5Designer.pc Qt5Help.pc Qt5UiTools.pc

post-install:
.for i in ${QTPKGCONFIGPC}
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
PLIST_VARS+=	dbus
.if ${PKG_BUILD_OPTIONS.qt5-qtbase:Mdbus}
PLIST.dbus=	yes
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
