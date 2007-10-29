# $NetBSD: options.mk,v 1.1 2007/10/29 13:11:11 uebayasi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs-w3m
PKG_SUPPORTED_OPTIONS=	emacs-w3m-mew

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Memacs-w3m-mew)
.include "../../mail/mew/buildlink3.mk"
PLIST_SUBST+=	FOR_mew=
.else
PLIST_SUBST+=	FOR_mew="@comment "
.endif
