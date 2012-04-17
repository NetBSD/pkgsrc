# $NetBSD: Makefile,v 1.8.2.1 2012/04/17 23:47:59 tron Exp $
#

DISTNAME=	${TYPO3NAME}
PKGNAME=	typo3-${VER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=typo3/}
DISTFILES=	${TYPO3NAME}${EXTRACT_SUFX} ${SITESRC}${EXTRACT_SUFX}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://typo3.com/
COMMENT=	The TYPO3 content management system LTS release.
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-{mysql,pgsql}>=5.1.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2.0:../../archivers/php-zlib/
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.2.0:../../textproc/php-json

PKG_DESTDIR_SUPPORT=	user-destdir

VER=		4.5.15
NO_BUILD=	yes
USE_TOOLS=	pax

TYPO3NAME=	typo3_src-${VER}
SITESRC=	dummy-${VER}
WRKSRC=		${WRKDIR}/${DISTNAME}

# maybe resides in lang/php/phpversion.mk
REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	typo3/cli_dispatch.phpsh

TYPO3DATADIR=	fileadmin fileadmin/_temp_ fileadmin/user_upload \
		typo3conf typo3conf/ext typo3conf/l10n typo3temp uploads \
		uploads/media uploads/pics uploads/tf

BUILD_DEFS+=	APACHE_GROUP

FILES_SUBST+=	TYPO3DIR=${TYPO3DIR:Q} SITEDIR=${SITEDIR:Q}
PLIST_SUBST+=	EGDIR=${EGDIR:Q} SITEDIR=${SITEDIR:Q} \
		TYPO3DIR=${TYPO3DIR:Q} TYPO3NAME=${TYPO3NAME:Q}

EGDIR=		share/examples/typo3

INSTALLATION_DIRS+= ${EGDIR} ${TYPO3DIR}/${SITEDIR} ${TYPO3DIR}/${TYPO3NAME}

CONF_FILES_PERMS+=	${EGDIR}/localconf.php \
			${TYPO3DIR}/${SITEDIR}/typo3conf/localconf.php \
			${REAL_ROOT_USER} ${APACHE_GROUP} 0660

.for d in ${TYPO3DATADIR}
OWN_DIRS_PERMS+= ${TYPO3DIR}/${SITEDIR}/${d} ${REAL_ROOT_USER} \
	${APACHE_GROUP} 0770
CHECK_PERMS_SKIP+= ${TYPO3DIR}/${SITEDIR}/${d}
.endfor

SUBST_CLASSES+=		conf
SUBST_FILES.conf+=	${WRKDIR}/README
SUBST_FILES.conf+=	${WRKSRC}/t3lib/config_default.php
SUBST_SED.conf+=        -e 's|@PREFIX@|${PREFIX:Q}|g'
SUBST_SED.conf+=        -e 's|@TYPO3DIR@|${TYPO3DIR:Q}|g'
SUBST_SED.conf+=        -e 's|@SITEDIR@|${SITEDIR:Q}|g'
SUBST_STAGE.conf=	post-configure

PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ \
			{ gsub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${TYPO3DIR:S|/|\\/|g}\/${TYPO3NAME}/ \
			{ gsub(/${TYPO3DIR:S|/|\\/|g}\/${TYPO3NAME}/, \
				"$${TYPO3DIR}/$${TYPO3NAME}") }
PRINT_PLIST_AWK+=	/^${TYPO3DIR:S|/|\\/|g}\/${SITEDIR}/ \
			{ gsub(/${TYPO3DIR:S|/|\\/|g}\/${SITEDIR}/, \
				"$${TYPO3DIR}/$${SITEDIR}") }

.include "../../mk/bsd.prefs.mk"

SITEDIR?=	www
TYPO3DIR?=	share/typo3

post-extract:
	${CP} ${FILESDIR}/README ${WRKDIR}

pre-install:
	${FIND} ${WRKSRC:Q} -name "*.orig*" -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; \
	    pax -rw . ${DESTDIR}${PREFIX}/${TYPO3DIR}/${TYPO3NAME}
	cd ${WRKDIR}/${SITESRC}; \
		pax -rw . ${DESTDIR}${PREFIX}/${TYPO3DIR}/${SITEDIR}
	${RM} -f ${DESTDIR}${PREFIX}/${TYPO3DIR}/${SITEDIR}/typo3conf/localconf.php
	${INSTALL_DATA} ${WRKDIR}/${SITESRC}/typo3conf/localconf.php \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
