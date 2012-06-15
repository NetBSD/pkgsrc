# $NetBSD: options.mk,v 1.12 2012/06/15 23:06:08 dholland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xterm
PKG_SUPPORTED_OPTIONS=		debug pcre freetype luit
PKG_SUGGESTED_OPTIONS=		freetype luit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+= --enable-trace
CONFIGURE_ARGS+= --enable-warnings
.elif defined(PKG_DEVELOPER) && !empty(PKG_DEVELOPER:M[Yy][Ee][Ss])
CONFIGURE_ARGS+= --enable-warnings
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+= --enable-freetype
.  include "../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-freetype
.endif
###
### XXX The configure test checks for pcreposix_regcomp in libpcreposix.
###	However, there is no such function [insofar as I can tell].
###	Moreover, libc's regex(3) functions are weak-aliased to those
###     within libc's namespace, so we should have no problems.
###
.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ENV+=		ac_cv_lib_pcreposix_pcreposix_regcomp=yes
.  include "../../devel/pcre/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mluit)
DEPENDS+=	luit-[0-9]*:../../x11/luit
CONFIGURE_ARGS+= --enable-luit --enable-mini-luit
.else
CONFIGURE_ARGS+= --disable-luit --disable-mini-luit
.endif
