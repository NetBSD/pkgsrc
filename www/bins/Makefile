# $NetBSD: Makefile,v 1.24 2004/04/27 05:44:23 snj Exp $
#

DISTNAME=	bins-1.1.25
CATEGORIES=	www graphics
MASTER_SITES=	http://jsautret.free.fr/BINS/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://bins.sautret.org/
COMMENT=	Static HTML photo album generator

DEPENDS+=	p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=	p5-Text-Iconv>=1.1:../../converters/p5-Text-Iconv
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
DEPENDS+=	p5-Image-Info>=1.10:../../graphics/p5-Image-Info
DEPENDS+=	p5-Image-Size>=2.980:../../graphics/p5-Image-Size
DEPENDS+=	p5-IO-String>=1.01:../../devel/p5-IO-String
DEPENDS+=	p5-PerlMagick>=5.3.9nb1:../../graphics/p5-PerlMagick
DEPENDS+=	p5-XML-Grove>=0.46.0.1:../../textproc/p5-XML-Grove
DEPENDS+=	p5-XML-Handler-YAWriter-0.23:../../textproc/p5-XML-YAWriter
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-HTML-Clean>=0.8:../../www/p5-HTML-Clean
DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template>=2.5:../../www/p5-HTML-Template
DEPENDS+=	p5-URI>=1.19:../../www/p5-URI

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
# bins-edit-gui not installed because many needed packages are missing
# bins_txt2xml not installed because it's an upgrade tool, and we didn't
# have previous versions in pkgsrc.
REPLACE_PERL=	bins bins_edit bins-edit-gui bins_cleanupgallery bins_txt2xml

post-patch:
	${MV} ${WRKSRC}/bins ${WRKSRC}/bins.bak
	${SED}	-e 's;/etc/bins;${PKG_SYSCONFDIR}/bins;g' \
		-e 's;/usr/local/share/locale;${PREFIX}/${PKGLOCALEDIR}/locale;g' \
		${WRKSRC}/bins.bak > ${WRKSRC}/bins

do-install:
	# Programs and manual pages
	${INSTALL_SCRIPT} ${WRKSRC}/anti_bins ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bins ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bins_cleanupgallery ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bins_edit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bins.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bins_edit.1 ${PREFIX}/man/man1
	# HTML documentation
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/bins
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/html/bins/
	# Example configuration file
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bins
	${INSTALL_DATA} ${WRKSRC}/binsrc ${PREFIX}/share/examples/bins/
	# template: default
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bins/templates.default
	${INSTALL_DATA} ${WRKSRC}/templates.default/*.html		\
		${PREFIX}/share/examples/bins/templates.default/
	# template: jab
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bins/templates.jab
	${INSTALL_DATA} ${WRKSRC}/templates.jab/*.html			\
		${PREFIX}/share/examples/bins/templates.jab/
	# template: joi
	${INSTALL_DATA_DIR}						\
		${PREFIX}/share/examples/bins/templates.joi		\
		${PREFIX}/share/examples/bins/templates.joi/static
	${INSTALL_DATA} ${WRKSRC}/templates.joi/*.html			\
		${PREFIX}/share/examples/bins/templates.joi/
	${INSTALL_DATA}							\
		${WRKSRC}/templates.joi/static/*.css			\
		${WRKSRC}/templates.joi/static/*.png			\
		${WRKSRC}/templates.joi/static/*.js			\
		${PREFIX}/share/examples/bins/templates.joi/static/
	# template: new
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bins/templates.new
	${INSTALL_DATA} ${WRKSRC}/templates.new/*.html			\
		${PREFIX}/share/examples/bins/templates.new/
	# template: satyap
	${INSTALL_DATA_DIR}						\
		${PREFIX}/share/examples/bins/templates.satyap		\
		${PREFIX}/share/examples/bins/templates.satyap/static
	${INSTALL_DATA} ${WRKSRC}/templates.satyap/*.html		\
		${PREFIX}/share/examples/bins/templates.satyap/
	${INSTALL_DATA}							\
		${WRKSRC}/templates.satyap/static/*.css			\
		${PREFIX}/share/examples/bins/templates.satyap/static/
	# Translations
	for lang in de eo es fi fr it ja nl pl ru zh; do \
		${INSTALL_DATA} ${WRKSRC}/intl/$$lang.mo \
		${PREFIX}/${PKGLOCALEDIR}/locale/$$lang/LC_MESSAGES/bins.mo; \
	done

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
