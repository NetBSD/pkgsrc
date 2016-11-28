# $NetBSD: options.mk,v 1.14.8.1 2016/11/28 20:22:06 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.w3m
PKG_SUPPORTED_OPTIONS=	inet6 migemo w3m-lynx-key
PKG_SUGGESTED_OPTIONS=	inet6

.if ${_W3M_USE_IMAGE} == "YES"
PKG_OPTIONS_REQUIRED_GROUPS+=	imagelib
PKG_SUGGESTED_OPTIONS+=		w3m-image-gtk2
.else
PKG_OPTIONS_OPTIONAL_GROUPS+=	imagelib
.endif
PKG_OPTIONS_GROUP.imagelib=	w3m-image-gdk-pixbuf w3m-image-imlib	\
				w3m-image-imlib2 w3m-image-gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mmigemo)
.include "../../lang/ruby/rubyversion.mk"
DEPENDS+=	${RUBY_PKGPREFIX}-migemo-[0-9]*:../../textproc/migemo
CONFIGURE_ARGS+=	--with-migemo="${LOCALBASE}/bin/migemo -t egrep ${LOCALBASE}/share/migemo/migemo-dict"
.else
CONFIGURE_ARGS+=	--without-migemo
.endif

.if !empty(PKG_OPTIONS:Mw3m-lynx-key)
CONFIGURE_ARGS+=	--enable-keymap=lynx
.else
CONFIGURE_ARGS+=	--enable-keymap=w3m
.endif

PLIST_VARS+=		image
.if !empty(PKG_OPTIONS:Mw3m-image-*)
.  for _imagelib in ${PKG_OPTIONS_GROUP.imagelib}
.    if !empty(PKG_OPTIONS:M${_imagelib})
_W3M_IMAGELIB=		${_imagelib:C|^w3m-image-||}
.    endif
.  endfor
USE_X11=		YES
CONFIGURE_ARGS+=	--enable-image=x11 --with-imagelib=${_W3M_IMAGELIB:Q}
PLIST.image=		yes
BUILDLINK_DEPMETHOD.libXt?=	build
.  include "../../x11/libXt/buildlink3.mk"
.  if empty(_W3M_IMAGELIB:Mgtk2)
.    include "../../graphics/${_W3M_IMAGELIB}/buildlink3.mk"
.  else
USE_TOOLS+=	pkg-config
.    include "../../x11/${_W3M_IMAGELIB}/buildlink3.mk"
.    include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.  endif
.else
CONFIGURE_ARGS+=	--disable-image
.endif
