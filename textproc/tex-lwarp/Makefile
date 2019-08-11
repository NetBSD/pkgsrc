# $NetBSD: Makefile,v 1.9 2019/08/11 10:16:12 markd Exp $

DISTNAME=	lwarp
PKGNAME=	tex-${DISTNAME}-0.73
TEXLIVE_REV=	51653

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lwarp
COMMENT=	Converts LaTeX to HTML
LICENSE=	lppl-1.3c

DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
DEPENDS+=	tex-xindy-[0-9]*:../../textproc/tex-xindy

REPLACE_TEXLUA=	bin/lwarpmk

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/lwarp/lwarpmk.lua ${WRKSRC}/bin/lwarpmk

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
