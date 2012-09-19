# $NetBSD: options.mk,v 1.1 2012/09/19 22:59:17 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-gnome2-desktop
PKG_SUPPORTED_OPTIONS=	evolution
PKG_SUGGESTED_OPTIONS=	evolution

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		evolution

.if !empty(PKG_OPTIONS:Mevolution)
PLIST.evolution=	yes
.include "../../mail/evolution-data-server/buildlink3.mk"
.endif
