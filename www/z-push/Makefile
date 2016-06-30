# $NetBSD: Makefile,v 1.3 2016/06/30 03:17:52 taca Exp $
#

DISTNAME=	z-push-${ZPUSH_VERSION}
ZPUSH_VERSION=	2.2.10
CATEGORIES=	www
MASTER_SITES=	http://download.z-push.org/final/2.2/

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://z-push.org/
COMMENT=	Open-source ActiveSync server

LICENSE=	gnu-agpl-v3

NO_BUILD=	yes

ZPUSHDIR=	${PREFIX}/share/z-push
EGDIR=		${PREFIX}/share/examples/z-push
DOCDIR=		${PREFIX}/share/doc/z-push
ZPUSHSTATEDIR=	${VARBASE}/z-push
ZPUSHLOGDIR=	${VARBASE}/log/z-push

BUILD_DEFS=	APACHE_USER APACHE_GROUP VARBASE
USE_TOOLS=	pax

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} bin

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-soap>=${PHP_BASE_VERS}:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl>=${PHP_BASE_VERS}:../../devel/php-pcntl
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=${PHP_BASE_VERS}:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-sysvshm>=${PHP_BASE_VERS}:../../devel/php-sysvshm
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=${PHP_BASE_VERS}:../../devel/php-sysvsem

PKG_SYSCONFSUBDIR=	z-push

MESSAGE_SUBST+=		ZPUSHDIR=${ZPUSHDIR:Q}
MESSAGE_SUBST+=		ZPUSHSTATEDIR=${ZPUSHSTATEDIR:Q}
MESSAGE_SUBST+=		ZPUSHLOGDIR=${ZPUSHLOGDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q}

OWN_DIRS_PERMS+=	${ZPUSHSTATEDIR}	\
			${APACHE_USER} ${APACHE_GROUP} 0750
OWN_DIRS_PERMS+=	${ZPUSHLOGDIR}		\
			${APACHE_USER} ${APACHE_GROUP} 0750

CONF_FILES_PERMS+=	${EGDIR}/config.php ${PKG_SYSCONFDIR}/config.php   \
			${ROOT_USER} ${APACHE_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/z-push.conf ${PKG_SYSCONFDIR}/z-push.conf \
			${ROOT_USER} ${APACHE_GROUP} 0640

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	z-push-admin.php
REPLACE_FILES.php+=	z-push-top.php
REPLACE_FILES.php+=	backend/zarafa/listfolders.php
REPLACE_FILES.php+=	tools/migrate-2.0.x-2.1.0.php

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	${WRKDIR}/z-push.conf
SUBST_VARS.conf=	ZPUSHDIR
SUBST_MESSAGE.conf=	Fixing Z-push directory path for apache configuration.

SUBST_CLASSES+=		state-dir
SUBST_STAGE.state-dir=	pre-configure
SUBST_FILES.state-dir=	config.php
SUBST_VARS.state-dir=	ZPUSHSTATEDIR
SUBST_MESSAGE.state-dir=Fixing Z-push state directory path.

post-extract:
	${CP} ${FILESDIR}/z-push.conf ${WRKDIR}/z-push.conf

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f
	${CHMOD} -x ${WRKSRC}/lib/syncobjects/syncresolverecipient.php

do-install:
	${INSTALL_DATA} ${WRKSRC}/config.php	\
		${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${WRKDIR}/z-push.conf	\
		${DESTDIR}${EGDIR}/z-push.conf

	cd ${WRKSRC} && pax -rwpam . ${DESTDIR}${ZPUSHDIR}

.	for f in INSTALL LICENSE
		${MV} ${DESTDIR}${ZPUSHDIR}/${f} ${DESTDIR}${DOCDIR}
.	endfor

	${LN} -sf ${ZPUSHDIR}/z-push-top.php	\
		${DESTDIR}${PREFIX}/bin/z-push-top
	${LN} -sf ${ZPUSHDIR}/z-push-admin.php	\
		${DESTDIR}${PREFIX}/bin/z-push-admin
	${LN} -sf ${PKG_SYSCONFDIR}/config.php	\
		${DESTDIR}${ZPUSHDIR}/config.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
