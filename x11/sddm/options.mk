# $NetBSD: options.mk,v 1.1 2025/12/30 04:00:08 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sddm
PKG_OPTIONS_REQUIRED_GROUPS+=	gui
PKG_OPTIONS_GROUP.gui=		qt5 qt6
PKG_SUGGESTED_OPTIONS+=		qt6

PLIST_VARS+=	qt5
PLIST_VARS+=	qt6

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.qt5=	yes
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=OFF
BUILDLINK_API_DEPENDS.qt5-qtbase+=     qt5-qtbase>=5.15.17
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt6)
PLIST.qt6=	yes
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.endif
