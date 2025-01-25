#	$NetBSD: options.mk,v 1.1 2025/01/25 21:07:19 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.otter-browser
PKG_OPTIONS_REQUIRED_GROUPS=	webkit
PKG_OPTIONS_GROUP.webkit=	qtwebkit qtwebengine

.include "../../mk/bsd.prefs.mk"

.for p in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M$p}
PKG_SUGGESTED_OPTIONS+=		qtwebengine
.  endif
.endfor
.if empty(PKG_SUGGESTED_OPTIONS:Mqtwebengine)
PKG_SUGGESTED_OPTIONS+=		qtwebkit
.endif

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mqtwebengine}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QTWEBENGINE=ON
.  include "../../x11/qt5-qtwebengine/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QTWEBENGINE=OFF
.endif

.if ${PKG_OPTIONS:Mqtwebkit}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QTWEBKIT=ON
.  include "../../x11/qt5-qtwebkit/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QTWEBKIT=OFF
.endif
