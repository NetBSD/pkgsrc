# $NetBSD: options.mk,v 1.2 2023/06/21 19:08:06 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.po4a
PKG_SUPPORTED_OPTIONS+=		latex sgml

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlatex)
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea	# kpsewhich
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex	# article.cls
.endif

.if !empty(PKG_OPTIONS:Msgml)
DEPENDS+=	docbook-[0-9]*:../../textproc/docbook	# DTDs
DEPENDS+=	opensp-[0-9]*:../../textproc/opensp	# onsgmls
.endif
