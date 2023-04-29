# $NetBSD: options.mk,v 1.1 2023/04/29 14:31:29 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.po4a
PKG_SUPPORTED_OPTIONS+=		latex

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlatex)
# kpsewhich
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
# article.cls
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
.endif
