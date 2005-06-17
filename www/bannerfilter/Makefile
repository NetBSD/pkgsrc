# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:40 jlam Exp $
#

DISTNAME=	bannerfilter-1.31
CATEGORIES=	www
MASTER_SITES=	http://phroggy.com/files/unix/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://phroggy.com/bannerfilter/
COMMENT=	Blocks advertising banners as squid redirector script

USE_PKGINSTALL=	YES
NO_BUILD=	YES

SHAREDIR=	${PREFIX}/share/bannerfilter
CONF_FILES=	${SHAREDIR}/bannerfilter.conf ${PKG_SYSCONFDIR}/bannerfilter.conf
REPLACE_PERL=	redirector.pl

SUBST_CLASSES+=	bf

SUBST_STAGE.bf=	post-patch
SUBST_FILES.bf=	bannerfilter.conf
SUBST_SED.bf=	-e s,@SHAREDIR@,${SHAREDIR},g

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${SHAREDIR}/www ${SHAREDIR}/doc ${SHAREDIR}/data
	${INSTALL_DATA} ${WRKSRC}/www/* ${SHAREDIR}/www/
	${INSTALL_DATA} ${WRKSRC}/*.data ${SHAREDIR}/data/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/COPYING ${WRKSRC}/README ${SHAREDIR}/doc/
	${INSTALL_DATA} ${WRKSRC}/bannerfilter.conf ${SHAREDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/redirector.pl ${PREFIX}/bin/bannerfilter-redirector.pl

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
