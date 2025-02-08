# $NetBSD: Makefile,v 1.44 2025/02/08 03:22:18 taca Exp $

PKGNAME=	${PHP_PKG_PREFIX}-fpm-${PHP_VERSION}
PKGREVISION=	12

HOMEPAGE=	https://php-fpm.org/
COMMENT=	FPM interface for ${PHP_PKG_PREFIX}
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

LIBTOOL_OVERRIDE=	# empty

.include "../../mk/bsd.prefs.mk"

FPM_USER?=		fpm
FPM_GROUP?=		www

BUILD_DEFS+=		VARBASE FPM_USER FPM_GROUP

PKG_USERS_VARS=		FPM_USER
PKG_GROUPS_VARS=	FPM_GROUP
PKG_GROUPS=		${FPM_GROUP}
PKG_USERS=		${FPM_USER}:${FPM_GROUP}

PKG_GECOS.${FPM_USER}=	PHP FPM daemon user
PKG_SHELL.${FPM_USER}=	${NOLOGIN}

CONF_FILES=		${PREFIX}/${PHP_EGDIR}/php-fpm.conf ${PKG_SYSCONFDIR}/php-fpm.conf

.include "../../lang/php/phpversion.mk"

.if ${PHP_VER} == 56
USE_TOOLS+=		autoconf269
.else
USE_TOOLS+=		autoconf
.endif

PLIST_VARS+=		fpmdotd

.if ${PHP_VER} >= 70
CONF_FILES+=		${PREFIX}/${PHP_EGDIR}/php-fpm.d/www.conf ${PKG_SYSCONFDIR}/php-fpm.d/www.conf
OWN_DIRS+=		${PKG_SYSCONFDIR}/php-fpm.d
INSTALLATION_DIRS+=	${PREFIX}/${PHP_EGDIR}/php-fpm.d
PLIST.fpmdotd=		yes
.endif

CONFIGURE_ARGS+=	--enable-fpm
CONFIGURE_ARGS+=	--with-fpm-user=${FPM_USER}
CONFIGURE_ARGS+=	--with-fpm-group=${FPM_GROUP}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

SMF_NAME=				php-fpm${PHP_VER}
RCD_SCRIPTS=				php_fpm${PHP_VER}
RCD_SCRIPT_SRC.php_fpm${PHP_VER}=	${FILESDIR}/php_fpm.sh

MESSAGE_SUBST+=		CGIDIR=${CGIDIR} VARBASE=${VARBASE}
INSTALLATION_DIRS+=	${PREFIX}/${PHP_EGDIR} ${PKGMANDIR}/man8 sbin

pre-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoconf -f

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/fpm/php-fpm ${DESTDIR}${PREFIX}/sbin/php-fpm${PHP_VER}
	${INSTALL_MAN} ${WRKSRC}/sapi/fpm/php-fpm.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/php-fpm${PHP_VER}.8
	${INSTALL_DATA} ${WRKSRC}/sapi/fpm/php-fpm.conf ${DESTDIR}${PREFIX}/${PHP_EGDIR}
.if ${PHP_VER} >= 70
	${INSTALL_DATA} ${WRKSRC}/sapi/fpm/www.conf ${DESTDIR}${PREFIX}/${PHP_EGDIR}/php-fpm.d
.endif

.include "${PHPPKGSRCDIR}/Makefile.php"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
