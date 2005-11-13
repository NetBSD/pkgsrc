# $NetBSD: Makefile,v 1.1.1.1 2005/11/13 06:13:53 minskim Exp $

DISTNAME=	base
PKGNAME=	tex-xmltex-1.9
WRKSRC=		${WRKDIR}/base
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/xmltex/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
TEX_ACCEPTED=	teTeX3

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC}; \
	pdfetex -ini -progname=xmltex "&latex" xmltex.ini; \
	pdfetex -ini -progname=pdfxmltex "&pdflatex" pdfxmltex.ini

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt ${PKG_TEXMFPREFIX}/web2c;

.include "../../mk/bsd.pkg.mk"
