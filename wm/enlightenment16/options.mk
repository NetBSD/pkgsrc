# $NetBSD: options.mk,v 1.2 2020/01/20 21:54:03 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.enlightenment16

PKG_SUPPORTED_OPTIONS=		pango pulseaudio vera-ttf
PKG_SUGGESTED_OPTIONS=		pango pulseaudio vera-ttf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpango)
CONFIGURE_ARGS+=	--enable-pango
.include "../../devel/pango/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pango
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-sound=pulseaudio
CONFIGURE_ARGS+=	--with-sndldr=sndfile
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-sound=no
CONFIGURE_ARGS+=	--with-sndldr=none
.endif

# The upstream package includes its own Vera fonts. Because these
# have a different license, and are also included in some base OS
# distributions (like NetBSD's native X11), this has been made
# optional.
.if !empty(PKG_OPTIONS:Mvera-ttf)
DEPENDS+=	vera-ttf>=1.10:../../fonts/vera-ttf
.endif
