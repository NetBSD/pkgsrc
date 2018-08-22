# $NetBSD: Makefile,v 1.19 2018/08/22 09:47:23 wiz Exp $
#

DISTNAME=	bannerfilter-1.31
PKGREVISION=	6
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
SUBST_STAGE.bf=	pre-configure
SUBST_FILES.bf=	bannerfilter.conf
SUBST_SED.bf=	-e s,@SHAREDIR@,${SHAREDIR},g

INSTALLATION_DIRS=	bin ${SHAREDIR}/www ${SHAREDIR}/doc ${SHAREDIR}/data

CHECK_PORTABILITY_SKIP+=	update.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/www/* ${DESTDIR}${SHAREDIR}/www/
	${INSTALL_DATA} ${WRKSRC}/*.data ${DESTDIR}${SHAREDIR}/data/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/COPYING ${WRKSRC}/README ${DESTDIR}${SHAREDIR}/doc/
	${INSTALL_DATA} ${WRKSRC}/bannerfilter.conf ${DESTDIR}${SHAREDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/redirector.pl ${DESTDIR}${PREFIX}/bin/bannerfilter-redirector.pl

.include "../../mk/bsd.pkg.mk"
