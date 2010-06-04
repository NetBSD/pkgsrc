# $NetBSD: Makefile,v 1.1.1.1 2010/06/04 09:20:00 wiz Exp $

DISTNAME=	moodle-1.9.8
CATEGORIES=	www
MASTER_SITES=	http://download.moodle.org/stable19/ \
		http://download2.moodle.org/stable19/ \
		http://download3.moodle.org/stable19/ \
		http://download4.moodle.org/stable19/
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

EGDIR=			share/examples/moodle
MOODLEDIR=		${PREFIX}/share/moodle
MOODLEDATADIR=		${PREFIX}/share/moodledata

PKG_DESTDIR_SUPPORT=	user-destdir
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

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../moodle.conf
SUBST_SED.paths=	-e "s,@MOODLEDIR@,${MOODLEDIR},g"

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing the path of php.
SUBST_STAGE.php=	post-patch
SUBST_FILES.php=	admin/mailout-debugger.php admin/process_email.php mod/chat/chatd.php
SUBST_SED.php=		-e "s,/usr/bin/php,/usr/pkg/bin/php,g"

SUBST_CLASSES+=         perl
SUBST_MESSAGE.paths=	Fixing the path of perl.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	filter/algebra/algebra2tex.pl
SUBST_SED.paths=	-e "s,/usr/bin/perl,/usr/pkg/bin/perl,g"

WRKSRC=			${WRKDIR}/moodle

post-extract:
	${CP} ${FILESDIR}/moodle.conf ${WRKDIR}/moodle.conf

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
