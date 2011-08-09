# $NetBSD: Makefile,v 1.5 2011/08/09 18:59:23 gls Exp $

DISTNAME=	moodle-2.1.1
CATEGORIES=	www
MASTER_SITES=	http://download.moodle.org/stable21/ \
		http://download2.moodle.org/stable21/ \
		http://download3.moodle.org/stable21/ \
		http://download4.moodle.org/stable21/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://www.moodle.org/
COMMENT=	Course management system based on social constructionism
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.3:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.2.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-xmlrpc>=5.2.0:../../net/php-xmlrpc
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.2.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=5.2.0:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.2.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.2.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.2.0:../../archivers/php-zip

EGDIR=			share/examples/moodle
MOODLEDIR=		${PREFIX}/share/moodle
MOODLEDATADIR=		${PREFIX}/moodledata

PKG_DESTDIR_SUPPORT=	destdir
INSTALLATION_DIRS=	${EGDIR} share/moodle

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PKG_INSTALLATION_TYPES=	overwrite pkgviews

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/moodle.conf \
			${PKG_SYSCONFDIR}/moodle.conf

NO_CONFIGURE=		YES
NO_BUILD=		YES

SUBST_CLASSES+=			bash
SUBST_MESSAGE.bash=		Replacing /bin/bash with ${SH}
SUBST_STAGE.bash=		post-patch
SUBST_FILES.bash=		lib/editor/tinymce/extra/tools/download_langs.sh
SUBST_SED.bash=			-e "s,/bin/bash,${SH},g"

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing pathnames in configuration file.
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	../moodle.conf
SUBST_SED.conf=		-e "s,@MOODLEDIR@,${MOODLEDIR},g"
SUBST_SED.conf+=	-e "s,@MOODLEDATADIR@,${MOODLEDATADIR},g"

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing the path of php.
SUBST_STAGE.php=	post-patch
SUBST_FILES.php=	admin/cli/mysql_engine.php admin/cli/maintenance.php admin/cli/cron.php
SUBST_FILES.php+=	admin/cli/reset_password.php admin/cli/automated_backups.php
SUBST_FILES.php+=	admin/cli/install.php admin/cli/install_database.php admin/cli/upgrade.php
SUBST_FILES.php+=	admin/mailout-debugger.php admin/process_email.php
SUBST_FILES.php+=	auth/ldap/cli/sync_users.php auth/cas/cli/sync_users.php auth/db/cli/sync_users.php
SUBST_FILES.php+=	enrol/ldap/cli/sync.php enrol/database/cli/sync.php enrol/category/cli/sync.php
SUBST_FILES.php+=	lib/pear/PHP/runsniffer lib/spikephpcoverage/src/cli/instrument.php
SUBST_FILES.php+=	mod/chat/chatd.php
SUBST_SED.php=		-e "s,/usr/bin/php,${PREFIX}/bin/php,g"

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing the path of perl.
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	filter/algebra/algebra2tex.pl
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

WRKSRC=			${WRKDIR}/moodle

post-extract:
	${CP} ${FILESDIR}/moodle.conf ${WRKDIR}/moodle.conf
	${RM} ${WRKSRC}/.gitignore

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	  ${DESTDIR}${MOODLEDIR}/{} \; -exec ${CHOWN} \
	  ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MOODLEDIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	  ${DESTDIR}${MOODLEDIR}/{} \; -exec ${CHOWN} \
	  ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MOODLEDIR}/{} \;
	${INSTALL_DATA} ${WRKDIR}/moodle.conf \
	  ${DESTDIR}${PREFIX}/${EGDIR}/moodle.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MOODLEDATADIR}
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MOODLEDATADIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
