# $NetBSD: Makefile,v 1.3 2001/11/28 23:59:29 jlam Exp $
#

DISTNAME=	validate
PKGNAME=	wdg-validate-1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/
DISTFILES=	validate sgml-lib.tar.gz README

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	HTML validator from the Web Design Group

DEPENDS+=	lq-sp>=1.3.4.5:../../textproc/lq-sp

DIST_SUBDIR=	wdg-validate
EXTRACT_ONLY=	sgml-lib.tar.gz

USE_BUILDLINK_ONLY=	YES
REPLACE_PERL=		validate.netbsd
NO_BUILD=		YES

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/validate ${WRKSRC}/validate.netbsd
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README ${WRKSRC}/README

do-configure:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g" \
		${WRKSRC}/validate.netbsd > ${WRKSRC}/validate

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/validate
	${INSTALL_SCRIPT} ${WRKSRC}/validate ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/validate.README
	${CP} -R ${WRKSRC}/lib/* ${PREFIX}/lib/validate

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
