# $NetBSD: options.mk,v 1.20 2020/06/21 17:53:01 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mlterm
PKG_SUPPORTED_OPTIONS=	cairo canna fcitx fribidi gdk_pixbuf2 ibus libind m17nlib mlterm-fb otl scim skk uim wnn4 xft2
PKG_SUGGESTED_OPTIONS=	cairo fribidi gdk_pixbuf2 m17nlib otl xft2
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	mlterm-fb
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		bidi cairo canna fb fbfiles fcitx ibus ind m17nlib otl scim skk uim wscons wnn x68kgrf xft2

.if !empty(PKG_OPTIONS:Mmlterm-fb)
.  if ${OPSYS} == "NetBSD"
.    if ${MACHINE_ARCH} == "m68k"
CONFIGURE_ARGS+=	--with-gui=xlib,wscons,x68kgrf
SPECIAL_PERMS+=		${PREFIX:Q}/bin/mlterm-x68kgrf ${SETUID_ROOT_PERMS}
PLIST.x68kgrf=		yes
.    else	# NetBSD && !m68k
CONFIGURE_ARGS+=	--with-gui=xlib,wscons
.    endif
SPECIAL_PERMS+=		${PREFIX:Q}/bin/mlterm-wscons ${SETUID_ROOT_PERMS}
PLIST.wscons=		yes
.  else		# !NetBSD (i.e. FreeBSD or Linux)
CONFIGURE_ARGS+=	--with-gui=xlib,fb
SPECIAL_PERMS+=		${PREFIX:Q}/bin/mlterm-fb ${SETUID_ROOT_PERMS}
PLIST.fb=		yes
.  endif
CONF_FILES+=		${EGDIR}/font-fb ${PKG_SYSCONFDIR}/font-fb
PLIST.fbfiles=		yes
.endif

.if !empty(PKG_OPTIONS:Mcairo)
.include "../../graphics/cairo/buildlink3.mk"
PLIST.cairo=		yes
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-canna
PLIST.canna=		yes
.else
CONFIGURE_ARGS+=	--disable-canna
.endif

.if !empty(PKG_OPTIONS:Mfribidi)
.include "../../converters/fribidi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fribidi
PLIST.bidi=		yes
.else
CONFIGURE_ARGS+=	--disable-fribidi
.endif

.if !empty(PKG_OPTIONS:Mgdk_pixbuf2)
CONFIGURE_ARGS+=	--with-imagelib=gdk-pixbuf
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfcitx)
.include "../../inputmethod/fcitx/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fcitx
PLIST.fcitx=		yes
.else
CONFIGURE_ARGS+=	--disable-fcitx
.endif

.if !empty(PKG_OPTIONS:Mibus)
.include "../../inputmethod/ibus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ibus
PLIST.ibus=		yes
.else
CONFIGURE_ARGS+=	--disable-ibus
.endif

.if !empty(PKG_OPTIONS:Mlibind)
CONFIGURE_ARGS+=	--enable-ind
PLIST.ind=		yes
LICENSE+=		AND gnu-lgpl-v2
.else
CONFIGURE_ARGS+=	--disable-ind
.endif

.if !empty(PKG_OPTIONS:Mm17nlib)
.include "../../devel/m17n-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-m17nlib
PLIST.m17nlib=		yes
.else
CONFIGURE_ARGS+=	--disable-m17nlib
.endif

.if !empty(PKG_OPTIONS:Motl)
.include "../../fonts/harfbuzz/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-otl
PLIST.otl=		yes
PLIST_SUBST+=		CORE="coreotl"
.else
CONFIGURE_ARGS+=	--disable-otl
PLIST_SUBST+=		CORE="core"
.endif

.if !empty(PKG_OPTIONS:Mscim)
.include "../../inputmethod/scim/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-scim
PLIST.scim=		yes
LICENSE+=		AND gnu-lgpl-v2
USE_LANGUAGES=		c c++
.else
CONFIGURE_ARGS+=	--disable-scim
.endif

.if !empty(PKG_OPTIONS:Mskk)
CONFIGURE_ARGS+=	--enable-skk
PLIST.skk=		yes
.else
CONFIGURE_ARGS+=	--disable-skk
.endif

.if !empty(PKG_OPTIONS:Muim)
.include "../../inputmethod/uim/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-uim
PLIST.uim=		yes
LICENSE+=		AND gnu-lgpl-v2
.else
CONFIGURE_ARGS+=	--disable-uim
.endif

.if !empty(PKG_OPTIONS:Mwnn4)
.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wnn
PLIST.wnn=		yes
.else
CONFIGURE_ARGS+=	--disable-wnn
.endif

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../x11/libXft/buildlink3.mk"
PLIST.xft2=		yes
CONFIGURE_ARGS+=	--enable-fontconfig
.else
CONFIGURE_ARGS+=	--disable-fontconfig
.endif

.if !empty(PKG_OPTIONS:Mcairo) && !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--with-type-engines=xcore,xft,cairo
.  if !empty(PKG_OPTIONS:Mmlterm-fb)
# --enable-anti-alias is also required for mlterm-fb
CONFIGURE_ARGS+=	--enable-anti-alias
.  endif
.elif !empty(PKG_OPTIONS:Mcairo)
CONFIGURE_ARGS+=	--with-type-engines=xcore,cairo
.elif !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--with-type-engines=xcore,xft
.else
CONFIGURE_ARGS+=	--with-type-engines=xcore
.endif
