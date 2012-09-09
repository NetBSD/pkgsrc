# $NetBSD: Makefile,v 1.21.2.1 2012/09/09 16:20:12 tron Exp $

DISTNAME=	mediawiki-${VER}.${PVER}
CATEGORIES=	www
MASTER_SITES=	http://download.wikimedia.org/mediawiki/${VER}/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://www.mediawiki.org/
COMMENT=	Free software wiki package originally written for Wikipedia
LICENSE=	gnu-gpl-v2

EGDIR=			share/examples/mediawiki
MEDIAWIKI=		${PREFIX}/share/mediawiki

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	${EGDIR} share/mediawiki

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PKG_INSTALLATION_TYPES=	overwrite pkgviews
VER=			1.19
PVER=			2

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

CONF_FILES=		${PREFIX}/${EGDIR}/mediawiki.conf \
			${PKG_SYSCONFDIR}/mediawiki.conf

NO_CONFIGURE=		YES
NO_BUILD=		YES

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../mediawiki.conf
SUBST_SED.paths=	-e "s,@MEDIAWIKI@,${MEDIAWIKI},g"

SUBST_CLASSES+=		sh
SUBST_STAGE.sh=		post-patch
SUBST_MESSAGE.sh=	Fixing path to sh
SUBST_FILES.sh+=	bin/ulimit-tvf.sh bin/ulimit.sh bin/ulimit4.sh
SUBST_FILES.sh+=	maintenance/storage/make-blobs
SUBST_FILES.sh+=	maintenance/dev/install.sh maintenance/dev/installphp.sh
SUBST_FILES.sh+=	maintenance/dev/installmw.sh maintenance/dev/start.sh
SUBST_FILES.sh+=	extensions/WikiEditor/modules/images/toolbar/png24/generate.sh
SUBST_SED.sh=		-e "s|/bin/bash|${SH}|"

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	maintenance/postgres/compare_schemas.pl
SUBST_FILES.perl+=	maintenance/postgres/mediawiki_mysql2postgres.pl
SUBST_SED.perl=		-e "s|/usr/bin/perl|${PERL5}|"

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing python path
SUBST_FILES.python+=	extensions/ConfirmEdit/captcha.py includes/zhtable/Makefile.py
SUBST_FILES.python+=	maintenance/cssjanus/cssjanus.py maintenance/cssjanus/csslex.py
SUBST_SED.python=	-e "s,/usr/bin/python,${PYTHONBIN},"

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing the path of php.
SUBST_STAGE.php=	post-patch
SUBST_FILES.php+=	includes/normal/UtfNormalTest2.php tests/RunSeleniumTests.php
SUBST_SED.php=		-e "s,/usr/bin/php,${PREFIX}/bin/php,g"

SUBST_CLASSES+=		php2
SUBST_MESSAGE.php2=	Fixing the path of php.
SUBST_STAGE.php2=	post-patch
SUBST_FILES.php2+=	tests/phpunit/phpunit.php
SUBST_SED.php2=          -e "s,/usr/bin/env php,${PREFIX}/bin/php,g"

post-extract:
	${CP} ${FILESDIR}/mediawiki.conf ${WRKDIR}/mediawiki.conf

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	  ${DESTDIR}${MEDIAWIKI}/{} \; -exec ${CHOWN} \
	  ${APACHE_USER}:${APACHE_GROUP} ${DESTDIR}${MEDIAWIKI}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d \! -name '.git*' \
	  -exec ${INSTALL_DATA} {} ${DESTDIR}${MEDIAWIKI}/{} \; \
	  -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	  ${DESTDIR}${MEDIAWIKI}/{} \;
	${INSTALL_DATA} ${WRKDIR}/mediawiki.conf \
	  ${DESTDIR}${PREFIX}/${EGDIR}/mediawiki.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
