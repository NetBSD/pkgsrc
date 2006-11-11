# $NetBSD: Makefile,v 1.10 2006/11/11 16:54:24 rillig Exp $
#

DISTNAME=	bannerfilter-1.31
CATEGORIES=	www
MASTER_SITES=	http://phroggy.com/files/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phroggy.com/bannerfilter/
COMMENT=	Blocks advertising banners as squid redirector script

NO_BUILD=	YES
USE_TOOLS+=	perl:run

SHAREDIR=	${PREFIX}/share/bannerfilter
CONF_FILES=	${SHAREDIR}/bannerfilter.conf ${PKG_SYSCONFDIR}/bannerfilter.conf
REPLACE_PERL=	redirector.pl

SUBST_CLASSES+=	bf
SUBST_STAGE.bf=	post-patch
SUBST_FILES.bf=	bannerfilter.conf
SUBST_SED.bf=	-e s,@SHAREDIR@,${SHAREDIR},g

INSTALLATION_DIRS=	bin ${SHAREDIR}/www ${SHAREDIR}/doc ${SHAREDIR}/data

CHECK_PORTABILITY_SKIP+=	update.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/www/* ${SHAREDIR}/www/
	${INSTALL_DATA} ${WRKSRC}/*.data ${SHAREDIR}/data/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/COPYING ${WRKSRC}/README ${SHAREDIR}/doc/
	${INSTALL_DATA} ${WRKSRC}/bannerfilter.conf ${SHAREDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/redirector.pl ${PREFIX}/bin/bannerfilter-redirector.pl

.include "../../mk/bsd.pkg.mk"
