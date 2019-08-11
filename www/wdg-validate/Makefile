# $NetBSD: Makefile,v 1.31 2019/08/11 13:25:09 wiz Exp $
#

DISTNAME=	validate-1.2.2
PKGNAME=	wdg-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://www.htmlhelp.com/tools/validator/offline/
DISTFILES=	${DISTNAME} wdg-sgml-lib-1.1.4.tar.gz README

MAINTAINER=	norm@sandbox.org.uk
HOMEPAGE=	http://www.htmlhelp.com/tools/validator/offline/
COMMENT=	HTML validator from the Web Design Group

DEPENDS+=	lq-sp>=1.3.4.5:../../textproc/lq-sp

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	validate
EXTRACT_ONLY=	wdg-sgml-lib-1.1.4.tar.gz
SITES.wdg-sgml-lib-1.1.4.tar.gz=	http://www.htmlhelp.com/tools/validator/src/

USE_TOOLS+=	perl:run pax
REPLACE_PERL=	validate
NO_BUILD=	YES

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	validate
SUBST_SED.paths=	-e 's,/usr/local/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,/usr/local/bin/lq-nsgmls,${LOCALBASE}/bin/lq-nsgmls,g'

INSTALLATION_DIRS+=	bin share/doc share/wdg/sgml-lib

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/validate
	${CP} ${DISTDIR}/${DIST_SUBDIR}/README ${WRKSRC}/README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/validate ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/validate.README
	cd ${WRKSRC}/wdg/sgml-lib && pax -rw * ${DESTDIR}${PREFIX}/share/wdg/sgml-lib/

.include "../../mk/bsd.pkg.mk"
