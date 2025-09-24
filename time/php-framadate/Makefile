# $NetBSD: Makefile,v 1.5 2025/09/24 15:16:41 spz Exp $

DISTNAME=	framadate-1.1.19
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time www
MASTER_SITES=	https://framagit.org/framasoft/framadate/framadate/-/archive/1.1.19/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://framagit.org/framasoft/framadate/framadate
COMMENT=	Poll and appointement web application
LICENSE=	cecill-b-v1

PHP_VERSIONS_INCOMPATIBLE=	56

.include "options.mk"

USE_LANGUAGES=	# none
USE_TOOLS=	pax

DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring

TOOL_DEPENDS+=	${PHP_PKG_PREFIX}-composer-[0-9]*:../../devel/php-composer
TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TOOL_DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
TOOL_DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl

.include "../../mk/bsd.prefs.mk"

PKG_USERS_VARS+=	APACHE_USER

DOCDIR=		share/doc/framadate
WWWDIR=		share/framadate

DOC_FILES=	AUTHORS.md CHANGELOG.md INSTALL.md LICENCE.fr.txt \
		LICENSE.en.txt README.md doc/TECHNICAL.md doc/TREEVIEW.md

WWW_DIRS=	action admin app css fonts images js locale tpl tpl_c vendor

MAKE_DIRS_PERMS+=	${WWWDIR}/tpl_c ${APACHE_USER} ${SHAREGRP} 0755
MAKE_DIRS_PERMS+=	${WWWDIR}/app/inc ${APACHE_USER} ${SHAREGRP} 0755

INSTALLATION_DIRS+=	${DOCDIR} ${WWWDIR}

REPLACE_SH+=	vendor/smarty/smarty/run-tests-for-all-php-versions.sh

# The composer run in post-extract updates from git and has a tendency
# to hang indefinitely. Also, the generated packages contain whatever was
# in git and aren't vetted by a a pkgsrc developer, which is a security
# issue for binary packages. And last not least the list of installed
# files changes, making the install phase fail.
#
NOT_FOR_BULK_PLATFORM=	*-*-*

post-extract:
	cd ${WRKSRC} && ${SETENV} COMPOSER_HOME=${WRKDIR}/composer composer${PHP_VER} update < /dev/null

do-build:
	cd ${WRKSRC} && ${CHMOD} -R og-w .
	${GREP} -rl '^#!/usr/bin/env' ${WRKSRC}/vendor | while read f ; do \
		${CP} $$f $$f.orig && \
		${SED} "s|^#!/usr/bin/env php|#!${PREFIX}/bin/php${PHP_VER}|" \
			$$f.orig > $$f && \
		${RM} $$f.orig ; \
	done

do-install:
	for f in ${DOC_FILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/${DOCDIR}; \
	done
	cd ${WRKSRC} && ${FIND} ${WWW_DIRS} *.php robots.txt -print | \
		${PAX} -rw -pmp ${DESTDIR}${PREFIX}/${WWWDIR}
	${RM} -rf ${DESTDIR}${PREFIX}/share/framadate/vendor/o80/i18n/.git
	${INSTALL_DATA} ${WRKSRC}/htaccess.txt \
		${DESTDIR}${PREFIX}/${WWWDIR}/.htaccess

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
