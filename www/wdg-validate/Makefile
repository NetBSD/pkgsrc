# $NetBSD: Makefile,v 1.12 2004/02/17 01:29:30 minskim Exp $
#

DISTNAME=	validate-1.2
PKGNAME=	wdg-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/
DISTFILES=	${DISTNAME} wdg-sgml-lib-1.1.3.tar.gz README

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	HTML validator from the Web Design Group

DEPENDS+=	lq-sp>=1.3.4.5:../../textproc/lq-sp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	validate
EXTRACT_ONLY=	wdg-sgml-lib-1.1.3.tar.gz
SITES_wdg-sgml-lib-1.1.3.tar.gz=	http://www.htmlhelp.com/tools/validator/src/

USE_BUILDLINK3=	YES
REPLACE_PERL=	validate.netbsd

INSTALLATION_DIRS+=	bin share/doc

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/validate.netbsd
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README ${WRKSRC}/README

do-build:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g" \
		${WRKSRC}/validate.netbsd > ${WRKSRC}/validate

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/wdg/sgml-lib
	${INSTALL_SCRIPT} ${WRKSRC}/validate ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/validate.README
	cd ${WRKSRC}/wdg/sgml-lib && ${PAX} -rw * ${PREFIX}/share/wdg/sgml-lib/

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
