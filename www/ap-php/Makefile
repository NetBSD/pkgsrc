# $NetBSD: Makefile,v 1.58 2024/06/15 08:01:18 jperkin Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-${PHP_VERSION}
PKGREVISION=		11
COMMENT=		Apache (${PKG_APACHE}) module for ${PKG_PHP}

CONFLICTS=		ap-php-[0-9]*

USE_TOOLS+=		autoconf lex pkg-config

APACHE_MODULE=		YES

FORTIFY_SUPPORTED=	no
SSP_SUPPORTED=		no

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.php"

# Ensure we export symbols in the linked shared object.
CONFIGURE_ENV+=		EXTRA_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:M*:Q}

INSTALLATION_DIRS=	lib/httpd

pre-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoconf -f

do-install:
	if [ -f ${WRKSRC}/.libs/libphp${PKG_PHP_MAJOR_VERS}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp${PKG_PHP_MAJOR_VERS}.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_MAJOR_VERS}.so;   \
	elif [ -f ${WRKSRC}/libs/libphp${PKG_PHP_MAJOR_VERS}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp${PKG_PHP_MAJOR_VERS}.so  \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_MAJOR_VERS}.so;   \
	elif [ -f ${WRKSRC}/.libs/libphp.so ]; then \
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_MAJOR_VERS}.so;   \
	fi

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
