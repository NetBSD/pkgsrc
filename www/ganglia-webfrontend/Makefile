# $NetBSD: Makefile,v 1.9 2009/02/16 13:53:45 joerg Exp $
#

DISTNAME=	ganglia-3.0.1
PKGNAME=	ganglia-webfrontend-3.0.1
PKGREVISION=	3
CATEGORIES=	www parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ganglia/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ganglia.sourceforge.net/
COMMENT=	PHP based frontend for the Ganglia Cluster Monitor

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.1:../../www/ap-php
DEPENDS+=	ganglia-monitor-core>=3.0.1:../../parallel/ganglia-monitor-core

USE_TOOLS+=	pax

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/web/

DOCROOT=	${PREFIX}/share/httpd/htdocs/ganglia
MESSAGE_SUBST+=	PREFIX=${PREFIX} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	${DOCROOT}

do-configure:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" ${WRKSRC}/conf.php >	\
		${WRKSRC}/conf.php.tmp &&			\
		${MV} ${WRKSRC}/conf.php.tmp ${WRKSRC}/conf.php
	${RM} ${WRKSRC}/conf.php.orig ${WRKSRC}/templates/default/footer.tpl.orig

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${DOCROOT}/

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
