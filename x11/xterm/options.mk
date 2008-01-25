# $NetBSD: options.mk,v 1.8 2008/01/25 18:22:01 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xterm
PKG_SUPPORTED_OPTIONS=	pcre xterm-luit freetype xterm-toolbar
PKG_OPTIONS_OPTIONAL_GROUPS=	color
PKG_OPTIONS_GROUP.color=	xterm-88color xterm-256color
PKG_SUGGESTED_OPTIONS=	xterm-256color xterm-luit xterm-toolbar

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxterm-88color)
CONFIGURE_ARGS+= --enable-88-color
.endif

.if !empty(PKG_OPTIONS:Mxterm-256color)
CONFIGURE_ARGS+= --enable-256-color
.endif

.if !empty(PKG_OPTIONS:Mxterm-luit)
CONFIGURE_ARGS+= --enable-luit
.endif

.if !empty(PKG_OPTIONS:Mfreetype)
CONFIGURE_ARGS+= --enable-freetype

.include "../../x11/libXft/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxterm-toolbar)
CONFIGURE_ARGS+= --enable-toolbar
.endif

###
### XXX The configure test checks for pcreposix_regcomp in libpcreposix.
###	However, there is no such function [insofar as I can tell].
###	Moreover, libc's regex(3) functions are weak-aliased to those
###     within libc's namespace, so we should have no problems.
###
.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+= --with-pcre
CONFIGURE_ENV+=  ac_cv_lib_pcreposix_pcreposix_regcomp=yes
.  include "../../devel/pcre/buildlink3.mk"
.endif
