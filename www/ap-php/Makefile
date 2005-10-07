# $NetBSD: Makefile,v 1.4 2005/10/07 16:51:41 jdolecek Exp $
#

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		1
COMMENT=		Apache (${PKG_APACHE}) module for ${PKG_PHP}

APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	libtool

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
