# $NetBSD: Makefile,v 1.13 2011/03/14 18:53:31 minskim Exp $

DISTNAME=	xmltex
PKGNAME=	tex-${DISTNAME}-1.9
PKGREVISION=	8
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

CONFLICTS+=	tex-bin-xmltex-[0-9]*
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-latexconfig-[0-9]*:../../print/tex-latexconfig
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS=	bin

TEX_FORMATS=	"xmltex pdftex language.dat *xmltex.ini\\npdfxmltex pdftex language.dat *pdfxmltex.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/xmltex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfxmltex

.include "../../mk/bsd.pkg.mk"
