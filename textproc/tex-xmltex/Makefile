# $NetBSD: Makefile,v 1.8 2008/06/22 02:55:53 reed Exp $

DISTNAME=	base
PKGNAME=	tex-xmltex-1.9
PKGREVISION=	4
WRKSRC=		${WRKDIR}/base
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/xmltex/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.dcarlisle.demon.co.uk/xmltex/manual.html
COMMENT=	Non-validating XML parser implemented in TeX

DIST_SUBDIR=	${PKGNAME_NOREV}
INSTALLATION_DIRS=	 ${PKG_LOCALTEXMFPREFIX}/tex/xmltex
NO_CONFIGURE=	yes
USE_DIRS+=	texmf-1.0
TEX_ACCEPTED=	teTeX3

CLASS_FILES=	englishutf16.xml langtest.xmt tei.xmt	\
		windows-1250.xmt englishutf8.xml mathml2.xmt testascii.cfg \
		xmltex.cfg iso-8859-1.xmt pdfxmltex.ini testascii.tex \
		xmltex.ini iso-8859-2.xmt portugeselatin1.xml testascii.xml \
		xmltex.tex koi8-r.xmt russiankoi8.xml testsec.tex \
		langtest.tex russianutf8.xml testsec.xml langtest.xml \
		sec.xmt utf-16.xmt

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC}; \
	${TEX} -ini -progname=xmltex "&latex" xmltex.ini; \
	${PDFTEX} -ini -progname=pdfxmltex "&pdflatex" pdfxmltex.ini

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_DATA} xmltex.fmt pdfxmltex.fmt ${PKG_LOCALTEXMFPREFIX}/web2c;
.for f in ${CLASS_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/tex/xmltex/
.endfor
	${RM} -f ${PREFIX}/bin/xmltex ${PREFIX}/bin/pdfxmltex
	${LN} -s ${TEX} ${PREFIX}/bin/xmltex
	${LN} -s ${PDFTEX} ${PREFIX}/bin/pdfxmltex

.include "../../mk/bsd.pkg.mk"
