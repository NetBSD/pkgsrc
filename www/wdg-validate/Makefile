# $NetBSD: Makefile,v 1.1.1.1 2001/05/30 09:44:53 abs Exp $
#

DISTNAME=	validate
PKGNAME=	wdg-validate-1.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/
DISTFILES=	validate sgml-lib.tar.gz

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	HTML validator from the Web Design Group

DEPENDS+=	lq-sp>=1.3.4.5:../../textproc/lq-sp

EXTRACT_ONLY=	sgml-lib.tar.gz

USE_PERL5=	yes

post-extract:
	${CP} ${DISTDIR}/validate ${WRKSRC}/validate.netbsd

do-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:'	\
	    < ${WRKSRC}/validate.netbsd		\
	    > ${WRKSRC}/validate

do-build:
	${PREFIX}/bin/perl ${WRKSRC}/validate -h > ${WRKSRC}/README

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/validate
	${INSTALL_SCRIPT} ${WRKSRC}/validate ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/validate.README
	${CP} -R ${WRKSRC}/lib/* ${PREFIX}/lib/validate

.include "../../mk/bsd.pkg.mk"
