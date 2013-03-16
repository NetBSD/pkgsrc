# $NetBSD: Makefile,v 1.7 2013/03/16 02:00:34 taca Exp $

PKGNAME=		${PHP_PKG_PREFIX}-fpm-${PHP_BASE_VERS}
CATEGORIES=		www

HOMEPAGE=		http://php-fpm.org/
MAINTAINER=		filip@joyent.com
COMMENT=		FPM interface for ${PKG_PHP}
LICENSE=		2-clause-bsd

PHP_VERSIONS_ACCEPTED=	53 54

USE_PHP_EXT_PATCHES=	yes
LIBTOOL_OVERRIDE=	# empty

BUILD_DEFS+=		VARBASE APACHE_USER APACHE_GROUP

EGDIR=			${PREFIX}/share/examples/php
CONF_FILES=		${EGDIR}/php-fpm.conf ${PKG_SYSCONFDIR}/php-fpm.conf
AUTO_MKDIRS=		yes

CONFIGURE_ARGS+=	--enable-fpm
CONFIGURE_ARGS+=	--with-fpm-user=${APACHE_USER}
CONFIGURE_ARGS+=	--with-fpm-group=${APACHE_GROUP}

RCD_SCRIPTS=		php_fpm
MESSAGE_SUBST+=		CGIDIR=${CGIDIR:Q}
MESSAGE_SUBST+=		VARBASE=${VARBASE:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/fpm/php-fpm ${DESTDIR}${PREFIX}/sbin/php-fpm
	${INSTALL_MAN} ${WRKSRC}/sapi/fpm/php-fpm.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/sapi/fpm/php-fpm.conf ${DESTDIR}${EGDIR}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.php"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
