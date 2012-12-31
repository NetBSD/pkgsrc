# $NetBSD: Makefile,v 1.36 2012/12/31 02:27:22 taca Exp $
#

DISTNAME=	geeklog-${VER}
PKGNAME=	geeklog-${VER:C/(sr|-)/./g}
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.geeklog.net/
COMMENT=	PHP/MySQL based application for managing dynamic web content
LICENSE=	gnu-gpl-v2

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.3.3:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.0:../../databases/php-mysql

USE_TOOLS+=	pax

VER=		1.8.2
NO_BUILD=	YES

PKG_GROUPS_VARS+=	APACHE_GROUP
BUILD_DEFS+=		GEEKLOG_SITEBASE

CHECK_PERMS_SKIP=	${GEEKLOG_PUB}/backend ${GEEKLOG_PUB}/images/*

GL_SYS=			emailgeeklogstories language plugins readme sql system
GL_TMPL_SUB=		backend images/articles images/library images/topics \
			images/userphotos

GL_CONF_FILES=		db-config.php system/lib-custom.php
GL_CONF_PUB_FILES=	public_html/siteconfig.php

CONF_FILES+=		${GL_EG}/geeklog.conf \
			${PKG_SYSCONFDIR}/geeklog.conf

.for f in ${GL_CONF_FILES}
CONF_FILES_PERMS+=	${GL_EG}/${f:T} ${GEEKLOG_BASE}/${f} \
			${REAL_ROOT_USER} ${APACHE_GROUP} 0660
.endfor

.for f in ${GL_CONF_PUB_FILES}
CONF_FILES_PERMS+=	${GL_EG}/${f:T} ${GEEKLOG_PUB}/${f:T} \
			${REAL_ROOT_USER} ${APACHE_GROUP} 0660
.endfor

OWN_DIRS_PERMS+=	${GEEKLOG_BASE}/backups ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
			${GEEKLOG_BASE}/data ${REAL_ROOT_USER} ${APACHE_GROUP} 0770 \
			${GEEKLOG_BASE}/logs ${REAL_ROOT_USER} ${APACHE_GROUP} 0775
OWN_DIRS+=		${GEEKLOG_PUB}

FILES_SUBST+=		APACHE_GROUP=${APACHE_GROUP:Q} \
			GEEKLOG_BASE=${GEEKLOG_BASE:Q} \
			GL_EG=${GL_EG:Q} \
			GEEKLOG_PUB=${GEEKLOG_PUB:Q} \
			GL_ADMIN=${GL_ADMIN:Q} \
			GL_TMPL_SUB=${GL_TMPL_SUB:Q} \
			GL_TMPL=${GL_TMPL:Q} \
			PAX=${PAX:Q}

PLIST_SUBST+=		GEEKLOG_BASE=${GEEKLOG_BASE:Q} \
			GEEKLOG_PUB=${GEEKLOG_PUB:Q} \
			GL_ADMIN=${GL_ADMIN:Q} \
			GL_TMPL=${GL_TMPL:Q} \
			GL_DOC=${GL_DOC:Q} \
			GL_EG=${GL_EG:Q}

.include "../../www/geeklog/Makefile.common"

PKG_SYSCONFSUBDIR?=	geeklog

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	${WRKDIR}/README
SUBST_FILES.paths+=	${WRKSRC}/emailgeeklogstories
SUBST_FILES.paths+=	${WRKSRC}/public_html/admin/install/index.php
SUBST_FILES.paths+=	${WRKDIR}/geeklog.conf
SUBST_SED.paths+=	-e 's,@GEEKLOG_BASE@,${GEEKLOG_BASE:Q},g'
SUBST_SED.paths+=	-e 's,@GEEKLOG_PUB@,${GEEKLOG_PUB:Q},g'
SUBST_SED.paths+=	-e 's,@GEEKLOG_SITESUBDIR@,${GEEKLOG_SITESUBDIR:Q},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:Q},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX:Q},g'
.if empty(GEEKLOG_SITEBASE)
SUBST_SED.conf+=	-e '/^Alias/s,^,\#,'
.endif
SUBST_STAGE.paths=	post-configure

INSTALLATION_DIRS=	${GEEKLOG_BASE} ${GEEKLOG_PUB} ${GL_TMPL}/images \
			share/examples/geeklog ${GL_DOC} ${GL_EG}

post-extract:
	${CP} ${FILESDIR}/README ${FILESDIR}/geeklog.conf ${WRKDIR}

pre-install:
	${FIND} ${WRKSRC} -type f -name "*.orig" -exec ${RM} -f {} \;
	cd ${WRKSRC}/public_html; \
		${FIND} ${GL_TMPL_SUB} -type f -exec ${CHMOD} -x {} \;
	${CHMOD} 0664 ${WRKSRC}/public_html/backend/geeklog.rss
	cd ${WRKSRC}/system; \
		${FIND} pear -type f -exec ${CHMOD} 0644 {} \;

do-install:
	${INSTALL_DATA} ${WRKDIR}/README ${DESTDIR}${PREFIX}/${GL_DOC}
.for f in ${GL_CONF_FILES} ${GL_CONF_PUB_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${GL_EG}
	${RM} ${WRKSRC}/${f}
.endfor
	${INSTALL_DATA} ${WRKDIR}/geeklog.conf ${DESTDIR}${PREFIX}/${GL_EG}
.for f in ${GL_SYS}
	cd ${WRKSRC}; pax -rw ${f} ${DESTDIR}${PREFIX}/${GEEKLOG_BASE}
.endfor
	cd ${WRKSRC}/public_html; \
		pax -rw admin ${DESTDIR}${PREFIX}/${GEEKLOG_BASE}; \
		${RM} -rf admin
.for d in ${GL_TMPL_SUB}
	cd ${WRKSRC}/public_html; \
		if [ -d ${d} ]; then \
			pax -rw ${d} ${DESTDIR}${PREFIX}/${GL_TMPL}; \
			${RM} -rf ${d}; \
		fi
.endfor
	cd ${WRKSRC}/public_html; pax -rw . ${DESTDIR}${PREFIX}/${GEEKLOG_PUB}

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
