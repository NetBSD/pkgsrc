# $NetBSD: Makefile,v 1.6 2020/03/20 11:58:29 nia Exp $
#

DISTNAME=	tei-xsl-5.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tei/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tei.sourceforge.net/
COMMENT=	XSLT Stylesheets to convert TEI to FO, HTML, and LaTeX

USE_LANGUAGES=	# none
NO_CONFIGURE=	YES
NO_BUILD=	YES

TEIXSLDIR=	${PREFIX}/share/xsl/tei-xsl
DOCDIR=		${PREFIX}/share/doc/tei-xsl

INSTALLATION_DIRS=	${TEIXSLDIR} ${DOCDIR}

XML_ENTRIES=	rewriteURI http://www.tei-c.org/Stylesheets/ \
		${TEIXSLDIR}

do-install:
	cd ${WRKSRC} && ${CP} -R p4 p5 ${DESTDIR}${TEIXSLDIR}
	cd ${WRKSRC}/doc && ${CP} -R * ${DESTDIR}${DOCDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
