# $NetBSD: Makefile,v 1.1.1.1 2002/07/04 19:37:38 wiz Exp $
#

DISTNAME=	bins-1.1.10
CATEGORIES=	www graphics
MASTER_SITES=	http://jsautret.free.fr/BINS/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://bins.sautret.org/
COMMENT=	static HTML photo album generator

DEPENDS+=	p5-Text-Iconv-1.1:../../converters/p5-Text-Iconv
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
DEPENDS+=	p5-Image-Info>=1.10:../../graphics/p5-Image-Info
DEPENDS+=	p5-Image-Size>=2.980:../../graphics/p5-Image-Size
DEPENDS+=	p5-PerlMagick>=5.3.9nb1:../../graphics/p5-PerlMagick
DEPENDS+=	p5-XML-Grove>=0.46.0.1:../../textproc/p5-XML-Grove
DEPENDS+=	p5-XML-Handler-YAWriter-0.23:../../textproc/p5-XML-YAWriter
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template>=2.5:../../www/p5-HTML-Template
DEPENDS+=	p5-URI>=1.19:../../www/p5-URI

USE_PERL5=	YES
# bins-edit-gui not installed because many needed packages are missing
# bins_txt2xml not installed because it's an upgrade tool, and we didn't
# have previous versions in pkgsrc.
REPLACE_PERL=	bins bins_edit bins-edit-gui bins_txt2xml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bins ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bins_edit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bins.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bins_edit.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bins/templates.default
	${INSTALL_DATA} ${WRKSRC}/templates/*.html \
		${PREFIX}/share/examples/bins/templates.default
	for lang in de fr it pl; do \
		${INSTALL_DATA} ${WRKSRC}/intl/$$lang.mo \
		${PREFIX}/${PKGLOCALEDIR}/locale/$$lang/LC_MESSAGES/bins.mo; \
	done

.include "../../mk/bsd.pkg.mk"
