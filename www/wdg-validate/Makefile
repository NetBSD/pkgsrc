# $NetBSD: Makefile,v 1.10 2003/11/12 10:43:18 wiz Exp $
#

DISTNAME=	validate-1.2
PKGNAME=	wdg-${DISTNAME}
WRKSRC=		${WRKDIR}
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/
DISTFILES=	${DISTNAME} wdg-sgml-lib-1.1.3.tar.gz README

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	HTML validator from the Web Design Group

DEPENDS+=	lq-sp>=1.3.4.5:../../textproc/lq-sp

DIST_SUBDIR=	validate
EXTRACT_ONLY=	wdg-sgml-lib-1.1.3.tar.gz
SITES_wdg-sgml-lib-1.1.3.tar.gz=	http://www.htmlhelp.com/tools/validator/src/

USE_BUILDLINK2=	YES
REPLACE_PERL=	validate.netbsd

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

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
