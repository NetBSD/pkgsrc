# $NetBSD: Makefile,v 1.14 2015/05/04 09:58:25 markd Exp $

DISTNAME=	xmltex
PKGNAME=	tex-${DISTNAME}-1.9
PKGREVISION=	9
TEXLIVE_REV=	35755

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-bin-xmltex-[0-9]*
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-latexconfig-[0-9]*:../../print/tex-latexconfig
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-xmltexconfig-[0-9]*:../../textproc/tex-xmltexconfig

INSTALLATION_DIRS=	bin

TEX_FORMATS=	"xmltex pdftex language.dat *xmltex.ini\\npdfxmltex pdftex language.dat *pdfxmltex.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/xmltex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfxmltex

.include "../../mk/bsd.pkg.mk"
