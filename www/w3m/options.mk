# $NetBSD: options.mk,v 1.4 2005/10/05 13:29:49 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.w3m
PKG_SUPPORTED_OPTIONS=	w3m-lynx-key w3m-m17n w3m-unicode
PKG_SUGGESTED_OPTIONS=	w3m-m17n

.if ${_W3M_USE_IMAGE} == "YES"
PKG_OPTIONS_OPTIONAL_GROUPS=	imagelib
PKG_OPTIONS_GROUP.imagelib=	w3m-image-gdk-pixbuf w3m-image-imlib	\
				w3m-image-imlib2
PKG_SUGGESTED_OPTIONS+=		w3m-image-gdk-pixbuf
.endif

# Memo about W3m configuration:
#
#	* pkgsrc should export only user configurable build options that can't
#	  be configured at run-time.
#
#	* As of 0.5, W3m is moving from English/Japanese (localized model) to
#	  internationalized model.  The set of its options are not well refined
#	  nor tested yet.  These configuration should be revisited later.
#
#	* --enable-m17n enables multibyte encoding support, and
#	  --enable-unicode adds UTF-7/UTF-8 support.  W3m has a home-grown M17N
#	  library (libwc) instead of using libc's I18N functions, that means
#	  enabling M17N much increases the size of W3m binary.  Additionary W3m
#	  has a home-grown Unicode mapping table, which is huge too!
#

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mw3m-m17n)
CONFIGURE_ARGS+=	--enable-m17n
.else
CONFIGURE_ARGS+=	--disable-m17n
.endif

.if !empty(PKG_OPTIONS:Mw3m-unicode)
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if !empty(PKG_OPTIONS:Mw3m-lynx-key)
CONFIGURE_ARGS+=	--enable-keymap=lynx
.else
CONFIGURE_ARGS+=	--enable-keymap=w3m
.endif

.if ${_W3M_USE_IMAGE} == "YES"
.  for _imagelib in ${PKG_OPTIONS_GROUP.imagelib}
.    if !empty(PKG_OPTIONS:M${_imagelib})
_W3M_IMAGELIB=		${_imagelib:C|^w3m-image-||}
.    endif
.  endfor
USE_X11=		YES
CONFIGURE_ARGS+=	--enable-image=x11 --with-imagelib=${_W3M_IMAGELIB}
PLIST_SUBST+=		USE_IMAGE=''
.  include "../../graphics/${_W3M_IMAGELIB}/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-image
PLIST_SUBST+=		USE_IMAGE='@comment '
.endif
