# $NetBSD: options.mk,v 1.2 2013/03/04 19:12:22 hiramatsu Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs-w3m
PKG_SUPPORTED_OPTIONS=	emacs-w3m-mew

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mew
.if !empty(PKG_OPTIONS:Memacs-w3m-mew)
MAKE_ENV+=	EMACS-W3M-MEW=1
.include "../../mail/mew/buildlink3.mk"
PLIST.mew=	yes
.endif
