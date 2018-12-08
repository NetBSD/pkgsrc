# $NetBSD: options.mk,v 1.1 2018/12/08 10:47:17 bouyer Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wxGTK30
.if ${OPSYS} != "Darwin"
PKG_OPTIONS_REQUIRED_GROUPS= gtk
PKG_OPTIONS_GROUP.gtk= gtk2 gtk3
PKG_SUGGESTED_OPTIONS= gtk3
.endif

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-osx_cocoa
CONFIGURE_ARGS+=	--without-macosx-sdk
CONFIGURE_ARGS+=	--without-macosx-version-min
CPPFLAGS+=		-D__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES=1
.else
.  if !empty(PKG_OPTIONS:Mgtk2)
PLIST_SRC+=		PLIST.gtk2
CONFIGURE_ARGS+=	--with-gtk=2
.include "../../x11/gtk2/buildlink3.mk"
. else
PLIST_SRC+=		PLIST.gtk3
CONFIGURE_ARGS+=	--with-gtk=3
.include "../../x11/gtk3/buildlink3.mk"
. endif
.endif
