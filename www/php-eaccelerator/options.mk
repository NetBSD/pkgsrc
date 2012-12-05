# $NetBSD: options.mk,v 1.1 2012/12/05 15:28:30 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eaccelerator
PKG_SUPPORTED_OPTIONS=	eaccelerator-disassembler
PKG_SUPPORTED_OPTIONS+=	eaccelerator-doc-comment-inclusion
PKG_SUGGESTED_OPTIONS=	eaccelerator-doc-comment-inclusion

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Meaccelerator-disassembler)
CONFIGURE_ARGS+=	--with-eaccelerator-disassembler
.endif

.if !empty(PKG_OPTIONS:Meaccelerator-doc-comment-inclusion)
CONFIGURE_ARGS+=	--with-eaccelerator-doc-comment-inclusion
.endif
