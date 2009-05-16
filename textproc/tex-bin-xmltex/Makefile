# $NetBSD: Makefile,v 1.1.1.1 2009/05/16 21:00:35 minskim Exp $
# TeX Live Revision 10592

DISTNAME=	bin-xmltex
PKGNAME=	tex-${DISTNAME}-0.8

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support for parsing XML documents

CONFLICTS+=	tex-xmltex<=1.9nb4
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-xmltex-[0-9]*:../../textproc/tex-xmltex

INSTALLATION_DIRS+=	bin

TEX_FORMAT_NAMES+=	xmltex

.include "../../print/texlive/module.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/xmltex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfxmltex

.include "../../mk/bsd.pkg.mk"
