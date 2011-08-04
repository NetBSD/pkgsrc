# $NetBSD: options.mk,v 1.7 2011/08/04 23:40:48 wiz Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.rxvt-unicode
PKG_SUPPORTED_OPTIONS=  perl unicode3 xft2 rxvt-term
PKG_SUGGESTED_OPTIONS=  perl unicode3 xft2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrxvt-term)
CONFIGURE_ARGS+=	--with-term=rxvt
.endif

PLIST_VARS+=		perl
.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=     	perl:run
CONFIGURE_ARGS+=	--enable-perl
PLIST.perl=		yes
.include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl
.else
CONFIGURE_ARGS+=	--disable-perl
.endif

# use 21 instead of 16 bits to represent unicode characters
.if !empty(PKG_OPTIONS:Municode3)
CONFIGURE_ARGS+=	--enable-unicode3
.else
CONFIGURE_ARGS+=	--disable-unicode3
.endif

.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft
.include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif
