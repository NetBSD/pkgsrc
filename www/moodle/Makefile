# $NetBSD: Makefile,v 1.101 2024/03/06 23:09:32 jym Exp $

DISTNAME=	moodle-4.3.3
CATEGORIES=	www
MASTER_SITES=	https://sourceforge.net/projects/moodle/files/Moodle/stable403/ \
		https://jaist.dl.sourceforge.net/project/moodle/Moodle/stable403/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://moodle.org/
COMMENT=	Course management system based on social constructionism
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=8.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=8.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=8.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=8.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=8.0:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=8.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=8.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=8.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=8.0:../../devel/php-opcache

EGDIR=			share/examples/moodle
MOODLEDIR=		${PREFIX}/share/moodle
MOODLEDATADIR=		${PREFIX}/moodledata

PKG_DESTDIR_SUPPORT=	destdir
INSTALLATION_DIRS=	${EGDIR} share/moodle

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PHP_VERSIONS_INCOMPATIBLE=	56 74

PKG_GROUPS_VARS=	APACHE_GROUP
PKG_USERS_VARS=		APACHE_USER
BUILD_DEFS+=		APACHE_USER APACHE_GROUP PKG_SYSCONFBASE

PKG_SYSCONFSUBDIR=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

CONF_FILES=		${PREFIX}/${EGDIR}/moodle.conf \
			${PKG_SYSCONFDIR}/moodle.conf
OWN_DIRS_PERMS+=	${MOODLEDATADIR} ${APACHE_USER} ${APACHE_GROUP} 0750

USE_TOOLS+=		pax
NO_BUILD=		yes

PLIST_SRC+=		${PKGDIR}/PLIST ${WRKDIR}/PLIST.AUTO

.include "../../mk/apache.mk"

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing pathnames in configuration file.
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	../moodle.conf
SUBST_VARS.conf=	MOODLEDIR
SUBST_VARS.conf+=	MOODLEDATADIR
.if ${PKG_APACHE} == "apache24"
SUBST_SED.conf+=	-e "/Order allow,deny/d"
SUBST_SED.conf+=	-e "s,Allow from all,Require all granted,g"
.endif

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Fixing the path of perl.
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	filter/algebra/algebra2tex.pl
SUBST_SED.perl=		-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

WRKSRC=			${WRKDIR}/moodle

post-extract:
	${CP} ${FILESDIR}/moodle.conf ${WRKDIR}/moodle.conf

post-patch:
	cd ${WRKDIR} && ${FIND} moodle -type f -print \
		| ${SED} -e 's,^,share/,' > ${WRKDIR}/PLIST.AUTO

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${MOODLEDIR}/
	${INSTALL_DATA} ${WRKDIR}/moodle.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/moodle.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MOODLEDATADIR}
	${CHOWN} ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MOODLEDATADIR}

.include "../../lang/php/json.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
