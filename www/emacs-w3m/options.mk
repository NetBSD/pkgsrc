# $NetBSD: options.mk,v 1.5 2026/09/26 07:21:48 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs-w3m
PKG_SUPPORTED_OPTIONS=	emacs-w3m-mew

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mew

.if !empty(PKG_OPTIONS:Memacs-w3m-mew)
.include "../../mail/mew/buildlink3.mk"
PLIST.mew=	yes
.endif
