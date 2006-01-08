# $NetBSD: Makefile,v 1.4 2006/01/08 14:00:12 tonio Exp $

DISTNAME=	base
PKGNAME=	tex-xmltex-1.9
PKGREVISION=	1
WRKSRC=		${WRKDIR}/base
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/xmltex/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
TEX_ACCEPTED=	teTeX2 teTeX3

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC}; \
	${TEX} -ini -progname=xmltex "&latex" xmltex.ini; \
	${PDFTEX} -ini -progname=pdfxmltex "&pdflatex" pdfxmltex.ini

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt ${PKG_LOCALTEXMFPREFIX}/web2c;

.include "../../mk/bsd.pkg.mk"
