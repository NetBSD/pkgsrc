# $NetBSD: Makefile,v 1.16 2013/03/16 07:21:24 obache Exp $
#

DISTNAME=	ganglia-3.1.2
PKGNAME=	ganglia-webfrontend-3.1.2
PKGREVISION=	2
CATEGORIES=	www parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ganglia.sourceforge.net/
COMMENT=	PHP based frontend for the Ganglia Cluster Monitor

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.1:../../www/ap-php
DEPENDS+=	ganglia-monitor-core>=3.1.2:../../parallel/ganglia-monitor-core

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/${DISTNAME}/web/

DOCROOT=	${PREFIX}/share/httpd/htdocs/ganglia
MESSAGE_SUBST+=	PREFIX=${PREFIX} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	${DOCROOT}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX
SUBST_FILES.prefix=	conf.php
SUBST_VARS.prefix=	PREFIX

JUNKFILES+=		AUTHORS COPYING Makefile.am conf.php.in conf.php.orig
JUNKFILES+=		templates/default/footer.tpl.orig version.php.in

do-build:
	${MKDIR} ${WRKDIR}/ganglia
	cd ${WRKSRC} && ${PAX} -rw . ${WRKDIR}/ganglia/
.for f in ${JUNKFILES}
	${RM} ${WRKDIR}/ganglia/${f}
.endfor

do-install:
	cd ${WRKDIR}/ganglia && ${PAX} -rw . ${DESTDIR}${DOCROOT}/

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
