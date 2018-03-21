# $NetBSD: options.mk,v 1.1 2018/03/21 23:18:09 gdt Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.privoxy
PKG_SUPPORTED_OPTIONS+=		inet6
PKG_SUGGESTED_OPTIONS+=		inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6-support
.else
CONFIGURE_ARGS+=	--disable-ipv6-support
.endif
