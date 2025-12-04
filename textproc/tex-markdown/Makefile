# $NetBSD: Makefile,v 1.1 2025/12/04 11:05:10 jperkin Exp $

DISTNAME=	markdown
PKGNAME=	tex-${DISTNAME}-3.12.0
TEXLIVE_REV=	76710

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/markdown
COMMENT=	Convert and render Markdown documents
LICENSE=	lppl-1.3c

REPLACE_TEXLUA=	texmf-dist/scripts/markdown/markdown2tex.lua

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
