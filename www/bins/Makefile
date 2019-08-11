# $NetBSD: Makefile,v 1.52 2019/08/11 13:24:17 wiz Exp $

DISTNAME=	bins-1.1.29
PKGREVISION=	11
CATEGORIES=	www graphics
MASTER_SITES=	http://zubro.chez.tiscali.fr/BINS/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://bins.sautret.org/
COMMENT=	Static HTML photo album generator

DEPENDS+=	p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=	p5-HTML-Clean>=0.8:../../www/p5-HTML-Clean
DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template>=2.5:../../www/p5-HTML-Template
DEPENDS+=	p5-Image-Info>=1.10:../../graphics/p5-Image-Info
DEPENDS+=	p5-Image-Size>=2.980:../../graphics/p5-Image-Size
DEPENDS+=	p5-IO-String>=1.01:../../devel/p5-IO-String
DEPENDS+=	p5-PerlMagick>=5.3.9nb1:../../graphics/p5-PerlMagick
#DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
DEPENDS+=	p5-Text-Iconv>=1.1:../../converters/p5-Text-Iconv
DEPENDS+=	p5-Text-Unaccent>=1.0:../../textproc/p5-Text-Unaccent
DEPENDS+=	p5-TimeDate>=1.0:../../time/p5-TimeDate
DEPENDS+=	p5-URI>=1.19:../../www/p5-URI
DEPENDS+=	p5-XML-Grove>=0.46.0.1:../../textproc/p5-XML-Grove
DEPENDS+=	p5-XML-Handler-YAWriter>=0.23:../../textproc/p5-XML-Handler-YAWriter
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser

USE_PKGLOCALEDIR=	YES

# bins-edit-gui not installed because many needed packages are missing
# bins_txt2xml not installed because it's an upgrade tool, and we didn't
# have previous versions in pkgsrc.
#
USE_TOOLS+=	perl:run
REPLACE_PERL=	bins bins_edit bins-edit-gui tools/bins_addtext \
		tools/bins_cleanupgallery tools/bins_txt2xml

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/bins \
			share/examples/bins

post-patch:
	${MV} ${WRKSRC}/bins ${WRKSRC}/bins.bak
	${SED}	-e 's;/etc/bins;${PKG_SYSCONFDIR}/bins;g' \
		-e 's;/usr/local/share/locale;${PREFIX}/${PKGLOCALEDIR}/locale;g' \
		${WRKSRC}/bins.bak > ${WRKSRC}/bins

do-install:
	# Programs and manual pages
	${INSTALL_SCRIPT} ${WRKSRC}/tools/anti_bins ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bins ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bins_cleanupgallery ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bins_edit ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/bins.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/bins_edit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	# HTML documentation
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DESTDIR}${PREFIX}/share/doc/bins/
	# Example configuration file
	${INSTALL_DATA} ${WRKSRC}/binsrc ${DESTDIR}${PREFIX}/share/examples/bins/
.for template in swigs
	# template: default
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/bins/templates.${template}
	${INSTALL_DATA} ${WRKSRC}/templates.${template}/*.*		\
		${DESTDIR}${PREFIX}/share/examples/bins/templates.${template}/
.endfor
.for template in joi marc martin mwolson petrus satyap
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/bins/templates.${template}/static
	${INSTALL_DATA} ${WRKSRC}/templates.${template}/*.*		\
		${DESTDIR}${PREFIX}/share/examples/bins/templates.${template}/
	${INSTALL_DATA}							\
		${WRKSRC}/templates.${template}/static/*		\
		${DESTDIR}${PREFIX}/share/examples/bins/templates.${template}/static/
.endfor
	# Translations
	for lang in ca de eo es fi fr hu it ja nl pl ru zh_TW; do \
		${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/$$lang/LC_MESSAGES; \
		${INSTALL_DATA} ${WRKSRC}/intl/$$lang.mo \
		${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/$$lang/LC_MESSAGES/bins.mo; \
	done

.include "../../mk/bsd.pkg.mk"
