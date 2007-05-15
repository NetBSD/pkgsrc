# $NetBSD: Makefile,v 1.13.2.1 2007/05/15 23:44:32 salo Exp $
#

PKGNAME=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-${PHP_BASE_VERS}
COMMENT=		Apache (${PKG_APACHE}) module for ${PKG_PHP}

CONFLICTS=		ap-php-[0-9]*

APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	# empty

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.php"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

INSTALLATION_DIRS=	lib/httpd

do-install:
	if [ -f ${WRKSRC}/.libs/libphp${PKG_PHP_VERSION}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp${PKG_PHP_VERSION}.so \
			${PREFIX}/lib/httpd/mod_php${PKG_PHP_VERSION}.so;   \
	elif [ -f ${WRKSRC}/libs/libphp${PKG_PHP_VERSION}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp${PKG_PHP_VERSION}.so  \
			${PREFIX}/lib/httpd/mod_php${PKG_PHP_VERSION}.so;   \
	fi

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
