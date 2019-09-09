# $NetBSD: options.mk,v 1.2 2019/09/09 12:59:06 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-control-center
PKG_SUPPORTED_OPTIONS=	libappindicator
PKG_SUGGESTED_OPTIONS=	libappindicator

PKG_OPTIONS_LEGACY_OPTS+=	libappindicator3:libappindicator

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibappindicator)
.include "../../devel/libappindicator/buildlink3.mk"
# configure automatically enables this option if it finds it in the
# environment. There are no additional files generated.
.endif
