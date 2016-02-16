# $NetBSD: Makefile,v 1.17 2016/02/16 13:05:23 fhajny Exp $
#

DISTNAME=	ganglia-web-3.7.1
PKGNAME=	${DISTNAME:S/web/webfrontend/}
CATEGORIES=	www parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ganglia.sourceforge.net/
COMMENT=	PHP based frontend for the Ganglia Cluster Monitor
LICENSE=	modified-bsd

DEPENDS+=	ganglia-monitor-core>=3.7.1:../../parallel/ganglia-monitor-core

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

MESSAGE_SUBST+=		DOCROOT=${DOCROOT}

PKG_SYSCONFSUBDIR=	ganglia
DOCROOT=		share/ganglia
EGDIR=			share/examples/ganglia

# Should match parallel/ganglia-monitor-core
GANGLIA_VARBASE?=	${VARBASE}/db
GWEB_DIR?=		${GANGLIA_VARBASE}/ganglia

OWN_DIRS_PERMS+=	${GWEB_DIR}/dwoo ${WWW_USER} ${WWW_GROUP} 0755
OWN_DIRS_PERMS+=	${GWEB_DIR}/dwoo/cache ${WWW_USER} ${WWW_GROUP} 0755
OWN_DIRS_PERMS+=	${GWEB_DIR}/dwoo/compiled ${WWW_USER} ${WWW_GROUP} 0755
PKG_SYSCONFDIR_PERMS=	${WWW_USER} ${WWW_GROUP} 0755
MAKE_DIRS_PERMS+=	${PKG_SYSCONFDIR}/filters ${WWW_USER} ${WWW_GROUP} 0755

CONF_FILES+=		${EGDIR}/conf.php ${PKG_SYSCONFDIR}/conf.php
CONF_FILES+=		${EGDIR}/apache.conf ${PKG_SYSCONFDIR}/apache.conf
CONF_FILES+=		${EGDIR}/nginx.conf ${PKG_SYSCONFDIR}/nginx.conf
CONF_FILES_PERMS+=	${EGDIR}/default.json ${PKG_SYSCONFDIR}/default.json ${WWW_USER} ${WWW_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/event_color.json ${PKG_SYSCONFDIR}/event_color.json ${WWW_USER} ${WWW_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/events.json ${PKG_SYSCONFDIR}/events.json ${WWW_USER} ${WWW_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/view_default.json ${PKG_SYSCONFDIR}/view_default.json ${WWW_USER} ${WWW_GROUP} 0644

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX
SUBST_FILES.prefix=	conf_default.php.in eval_conf.php conf/conf.php conf/apache.conf conf/nginx.conf
SUBST_VARS.prefix=	PREFIX PKG_SYSCONFDIR PKG_SYSCONFBASE VARBASE DOCROOT EGDIR

REPLACE_SH+=		nagios/*.sh

MAKE_FLAGS+=		GCONFDIR=${PKG_SYSCONFDIR}
MAKE_FLAGS+=		GDESTDIR=${PREFIX}/${DOCROOT}
MAKE_FLAGS+=		GMETAD_ROOTDIR=${GANGLIA_VARBASE}/ganglia
MAKE_FLAGS+=		GWEB_STATEDIR=${GWEB_DIR}

INSTALLATION_DIRS+=	${DOCROOT} ${EGDIR}

post-extract:
	${INSTALL_DATA} ${FILESDIR}/conf.php ${WRKSRC}/conf
	${INSTALL_DATA} ${FILESDIR}/apache.conf ${WRKSRC}/conf
	${INSTALL_DATA} ${FILESDIR}/nginx.conf ${WRKSRC}/conf

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp *.php *.html *.css api css	\
		docs dwoo graph.d img js lib nagios templates test	\
		${DESTDIR}${PREFIX}/${DOCROOT}
	cd ${WRKSRC}/conf && ${PAX} -rw -pp * ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
