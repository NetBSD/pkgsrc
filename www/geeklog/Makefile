# $NetBSD: Makefile,v 1.19.4.1 2008/09/10 10:30:49 tron Exp $
#

DISTNAME=	geeklog-${VER}
PKGNAME=	geeklog-${VER:C/(sr|-)/./g}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.geeklog.net/
COMMENT=	PHP/MySQL based application for managing dynamic web content

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.0:../../databases/php-mysql

USE_TOOLS+=	pax:run

VER=		1.4.1
NO_BUILD=	YES

PKG_GROUPS_VARS+=	APACHE_GROUP
BUILD_DEFS+=		GEEKLOG_SITEBASE

GEEKLOG_SYS=		emailgeeklogstories language plugins readme sql system
GEEKLOG_TMPL_SUB=	backend images/articles images/library \
			images/topics images/userphotos

GEEKLOG_CONF_FILES=	config.php plugins/calendar/config.php \
			plugins/links/config.php plugins/polls/config.php \
			plugins/spamx/config.php \
			plugins/staticpages/config.php \
			system/lib-custom.php

CONF_FILES+=		${GEEKLOG_EXAMPLESDIR}/geeklog.conf \
			${PKG_SYSCONFDIR}/geeklog.conf

.for f in ${GEEKLOG_CONF_FILES}
CONF_FILES_PERMS+=	${GEEKLOG_EXAMPLESDIR}/${f} \
			${GEEKLOG_DIR}/${f} \
			${BINOWN} ${APACHE_GROUP} 0640
.endfor

OWN_DIRS_PERMS+=	${GEEKLOG_DIR}/backups ${BINOWN} ${APACHE_GROUP} 0770 \
			${GEEKLOG_DIR}/data ${BINOWN} ${APACHE_GROUP} 0770 \
			${GEEKLOG_DIR}/logs ${BINOWN} ${APACHE_GROUP} 0775
OWN_DIRS+=		${GEEKLOG_PUB}

FILES_SUBST+=		APACHE_GROUP=${APACHE_GROUP:Q} \
			GEEKLOG_DIR=${GEEKLOG_DIR:Q} \
			GEEKLOG_EXAMPLESDIR=${GEEKLOG_EXAMPLESDIR:Q} \
			GEEKLOG_PUBDIR=${GEEKLOG_PUBDIR:Q} \
			GEEKLOG_ADMIN_DIR=${GEEKLOG_ADMIN_DIR:Q} \
			GEEKLOG_TMPL_SUB=${GEEKLOG_TMPL_SUB:Q} \
			GEEKLOG_TMPL_DIR=${GEEKLOG_TMPL_DIR:Q} \
			PAX=${PAX:Q}

PLIST_SUBST+=		GEEKLOG_BASE=${GEEKLOG_BASE:Q} \
			GEEKLOG_PUB=${GEEKLOG_PUB:Q} \
			GEEKLOG_ADMIN=${GEEKLOG_ADMIN:Q} \
			GEEKLOG_TMPL=${GEEKLOG_TMPL:Q}

.include "../../www/geeklog/Makefile.common"

PKG_SYSCONFSUBDIR?=	geeklog

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	${WRKDIR}/README ${WRKDIR}/createdb.php
SUBST_FILES.paths+=	${WRKSRC}/config.php ${WRKSRC}/emailgeeklogstories
SUBST_FILES.paths+=	${WRKSRC}/public_html/lib-common.php
SUBST_SED.paths+=	-e 's,@GEEKLOG_DIR@,${GEEKLOG_DIR:Q},g'
SUBST_SED.paths+=	-e 's,@GEEKLOG_EXAMPLESDIR@,${GEEKLOG_EXAMPLESDIR:Q},g'
SUBST_SED.paths+=	-e 's,@GEEKLOG_PUBDIR@,${GEEKLOG_PUBDIR:Q},g'
SUBST_SED.paths+=	-e 's,@GEEKLOG_SITESUBDIR@,${GEEKLOG_SITESUBDIR:Q},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:Q},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.paths=	post-configure

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/geeklog.conf
SUBST_SED.conf+=	-e 's,@GEEKLOG_DIR@,${GEEKLOG_DIR:Q},g'
SUBST_SED.conf+=	-e 's,@GEEKLOG_PUBDIR@,${GEEKLOG_PUBDIR:Q},g'
.if empty(GEEKLOG_SITEBASE)
SUBST_SED.conf+=	-e '/^Alias/s,^,\#,'
.endif
SUBST_STAGE.conf=	post-configure

INSTALLATION_DIRS=	${GEEKLOG_BASE} ${GEEKLOG_PUB} ${GEEKLOG_TMPL}/images \
			share/examples/geeklog ${GEEKLOG_DOCDIR}

post-extract:
	${CP} ${FILESDIR}/README ${FILESDIR}/createdb.php \
		${FILESDIR}/geeklog.conf ${WRKDIR}

pre-install:
	${FIND} ${WRKSRC:Q} -name "*.orig*" -exec ${RM} -f {} \;
	cd ${WRKSRC}/public_html; \
		${FIND} ${GEEKLOG_TMPL_SUB} -type f -exec ${CHMOD} -x {} \;
	${CHMOD} 0664 ${WRKSRC}/public_html/backend/geeklog.rss
	cd ${WRKSRC}/system; \
		${FIND} pear -type f -exec ${CHMOD} 0644 {} \;

do-install:
	${INSTALL_DATA} ${WRKDIR}/README ${DESTDIR}${GEEKLOG_DOCDIR}
.for f in ${GEEKLOG_CONF_FILES}
	${INSTALL_DATA_DIR} ${DESTDIR}${GEEKLOG_EXAMPLESDIR}/${f:H}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${GEEKLOG_EXAMPLESDIR}/${f}
	${RM} ${WRKSRC}/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/createdb.php ${DESTDIR}${GEEKLOG_DIR}
	${INSTALL_DATA} ${WRKDIR}/geeklog.conf ${DESTDIR}${GEEKLOG_EXAMPLESDIR}
.for f in ${GEEKLOG_SYS}
	cd ${WRKSRC}; pax -rw ${f} ${DESTDIR}${GEEKLOG_DIR}
.endfor
	cd ${WRKSRC}/public_html; \
		pax -rw admin ${DESTDIR}${GEEKLOG_DIR}; \
		${RM} -rf admin
.for d in ${GEEKLOG_TMPL_SUB}
	cd ${WRKSRC}/public_html; \
		if [ -d ${d} ]; then \
			pax -rw ${d} ${DESTDIR}${GEEKLOG_TMPL_DIR}; \
			${RM} -rf ${d}; \
		fi
.endfor
	cd ${WRKSRC}/public_html; pax -rw . ${DESTDIR}${GEEKLOG_PUBDIR}

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
