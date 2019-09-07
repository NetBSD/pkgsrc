# $NetBSD: options.mk,v 1.1 2019/09/07 04:02:58 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-control-center
PKG_SUPPORTED_OPTIONS=	libappindicator3
PKG_SUGGESTED_OPTIONS=	libappindicator3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibappindicator3)
.include "../../devel/libappindicator3/buildlink3.mk"
# configure automatically enables this option if it finds it in the
# environment. There are no additional files generated.
.endif
