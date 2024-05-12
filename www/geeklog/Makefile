# $NetBSD: Makefile,v 1.49 2024/05/12 14:36:46 taca Exp $
#

DISTNAME=	geeklog-${VER}
PKGNAME=	${PHP_PKG_PREFIX}-geeklog-${VER:C/(sr|-)/./g}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=Geeklog-Core/}
GITHUB_PROJECT=	geeklog
GITHUB_RELEASE=	v${VER}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.geeklog.net/
COMMENT=	PHP/MySQL based application for managing dynamic web content
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=7.4.0:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=7.4.0:../../converters/php-mbstring

PHP_VERSIONS_ACCEPTED=	74 81

EXTRACT_DIR=	${WRKSRC}
USE_TOOLS+=	pax

VER=		2.2.2
NO_BUILD=	YES

PKG_GROUPS_VARS+=	APACHE_GROUP
BUILD_DEFS+=		GEEKLOG_SITEBASE

CHECK_PERMS_SKIP=	${GEEKLOG_PUB}/backend ${GEEKLOG_PUB}/images/*

GL_SYS=			cron-emailgeeklogdailydigest \
			cron-emailgeeklogdatabasebackup language plugins \
			readme sql system
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

# Geeklog system
GL_ADMIN=		${GEEKLOG_BASE}/admin
GL_TMPL=		${GEEKLOG_BASE}/default

# for Geeklog public area
GL_DOC=			share/doc/geeklog
GL_EG=			share/examples/geeklog

PKG_SYSCONFSUBDIR?=	geeklog

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	${WRKDIR}/README
SUBST_FILES.paths+=	${WRKDIR}/geeklog.conf
SUBST_FILES.paths+=	cron-emailgeeklogdailydigest
SUBST_FILES.paths+=	cron-emailgeeklogdatabasebackup
SUBST_VARS.paths=	GEEKLOG_BASE
SUBST_VARS.paths+=	GEEKLOG_PUB
SUBST_VARS.paths+=	GEEKLOG_SITESUBDIR
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	PREFIX
.if empty(GEEKLOG_SITEBASE)
SUBST_SED.paths+=	-e '/^Alias/s,^,\#,'
.endif
SUBST_STAGE.paths=	post-configure

INSTALLATION_DIRS=	${GEEKLOG_BASE} ${GEEKLOG_PUB} ${GL_TMPL}/images \
			share/examples/geeklog ${GL_DOC} ${GL_EG}

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} == 74
DEPENDS+=	${PHP_PKG_PREFIX}-json>=7.4.0:../../textproc/php-json
.endif

.include "options.mk"

GEEKLOG_BASE?=		share/geeklog

# Geeklog's basic directories.
GEEKLOG_PUB?=		share/httpd/geeklog

# access Geeklog as its own directory?
GEEKLOG_SITEBASE?=	geeklog

BUILD_DEFS+=		GEEKLOG_BASE GEEKLOG_PUB GEEKLOG_SITEBASE

.if !empty(GEEKLOG_SITEBASE)
GEEKLOG_SITESUBDIR=	/${GEEKLOG_SITEBASE}
.endif

PRINT_PLIST_AWK+=	/^${GL_ADMIN:S|/|\\/|g}/ \
			{ gsub(/${GL_ADMIN:S|/|\\/|g}/, "$${GL_ADMIN}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${GL_TMPL:S|/|\\/|g}/ \
			{ gsub(/${GL_TMPL:S|/|\\/|g}/, "$${GL_TMPL}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${GL_DOC:S|/|\\/|g}/ \
			{ gsub(/${GL_DOC:S|/|\\/|g}/, "$${GL_DOC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${GL_EG:S|/|\\/|g}/ \
			{ gsub(/${GL_EG:S|/|\\/|g}/, "$${GL_EG}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_BASE:S|/|\\/|g}\/backups/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_BASE:S|/|\\/|g}\/data/ { next; }
PRINT_PLIST_AWK+=	/^?${GEEKLOG_BASE:S|/|\\/|g}\/logs/ { next; }
PRINT_PLIST_AWK+=	/${GEEKLOG_BASE:S|/|\\/|g}\/db-config.php/ { next; }
PRINT_PLIST_AWK+=	/${GEEKLOG_BASE:S|/|\\/|g}\/system\/lib-custom.php/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_BASE:S|/|\\/|g}/ \
			{ gsub(/${GEEKLOG_BASE:S|/|\\/|g}/, "$${GEEKLOG_BASE}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}\/admin/ { next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}\/backend/ { next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}\/images\/articles/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}\/images\/library/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}\/images\/topics/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}\/images\/userphotos/ \
			{ next; }
PRINT_PLIST_AWK+=	/${GEEKLOG_PUB:S|/|\\/|g}\/siteconfig.php/ { next; }
PRINT_PLIST_AWK+=	/^${GEEKLOG_PUB:S|/|\\/|g}/ \
			{ gsub(/${GEEKLOG_PUB:S|/|\\/|g}/, "$${GEEKLOG_PUB}"); \
			print; next; }

post-extract:
	${CP} ${FILESDIR}/README ${FILESDIR}/geeklog.conf ${WRKDIR}

pre-install:
	${FIND} ${WRKSRC} -type f -name "*.orig" -exec ${RM} -f {} \;
	cd ${WRKSRC}/public_html; \
		${FIND} ${GL_TMPL_SUB} -type f -exec ${CHMOD} -x {} \;
	${CHMOD} 0664 ${WRKSRC}/public_html/backend/geeklog.rss
	cd ${WRKSRC}/system/vendor/bin; \
		${FIND} . -type f -exec ${CHMOD} 0644 {} \;

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
		if ${TEST} -d ${d}; then \
			pax -rw ${d} ${DESTDIR}${PREFIX}/${GL_TMPL}; \
			${RM} -rf ${d}; \
		fi
.endfor
	cd ${WRKSRC}/public_html; pax -rw . ${DESTDIR}${PREFIX}/${GEEKLOG_PUB}

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
