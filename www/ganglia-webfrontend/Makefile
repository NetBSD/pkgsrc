# $NetBSD: Makefile,v 1.2 2005/02/10 02:34:54 jschauma Exp $
#

DISTNAME=	ganglia-3.0.0
PKGNAME=	ganglia-webfrontend-3.0.0
CATEGORIES=	www parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://ganglia.sourceforge.net/
COMMENT=	PHP based frontend for the Ganglia Cluster Monitor

DEPENDS+=	ap-php>=4.1:../../www/ap-php
DEPENDS+=	ganglia-monitor-core>=3.0.0:../../parallel/ganglia-monitor-core

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/ganglia-3.0.0/web/

DOCROOT=	${PREFIX}/share/httpd/htdocs/ganglia
MESSAGE_SUBST+=	PREFIX=${PREFIX} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

do-configure:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${WRKSRC}/conf.php >	\
		${WRKSRC}/conf.php.tmp &&			\
		${MV} ${WRKSRC}/conf.php.tmp ${WRKSRC}/conf.php
	${RM} ${WRKSRC}/conf.php.orig ${WRKSRC}/templates/default/footer.tpl.orig

do-install:
	${INSTALL_DATA_DIR} ${DOCROOT}
	cd ${WRKSRC} && ${PAX} -rw . ${DOCROOT}/

.include "../../mk/bsd.pkg.mk"
