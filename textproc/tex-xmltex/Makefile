# $NetBSD: Makefile,v 1.18 2022/09/29 06:16:00 markd Exp $

DISTNAME=	xmltex
PKGNAME=	tex-${DISTNAME}-1.9
PKGREVISION=	11
TEXLIVE_REV=	35755

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xmltex
COMMENT=	Non-validating XML parser implemented in TeX
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-bin-xmltex-[0-9]*
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-latexconfig-[0-9]*:../../print/tex-latexconfig
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-xmltexconfig-[0-9]*:../../textproc/tex-xmltexconfig

INSTALLATION_DIRS=	bin

TEX_FORMATS=	"xmltex pdftex language.dat *xmltex.ini\\npdfxmltex pdftex language.dat *pdfxmltex.ini\\n"
TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/xmltex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfxmltex

.include "../../mk/bsd.pkg.mk"
