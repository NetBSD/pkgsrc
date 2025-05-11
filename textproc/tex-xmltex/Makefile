# $NetBSD: Makefile,v 1.19 2025/05/11 04:05:36 markd Exp $

DISTNAME=	xmltex
PKGNAME=	tex-${DISTNAME}-1.9.71362
TEXLIVE_REV=	71362

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xmltex
COMMENT=	Non-validating XML parser implemented in TeX
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-bin-xmltex-[0-9]*
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
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
