# $NetBSD: Makefile,v 1.21 2008/06/12 02:14:54 joerg Exp $
#

PKGNAME=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-${PHP_BASE_VERS}
PKGREVISION=		1
COMMENT=		Apache (${PKG_APACHE}) module for ${PKG_PHP}

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		ap-php-[0-9]*

USE_TOOLS+=		lex

APACHE_MODULE=		YES

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.php"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

INSTALLATION_DIRS=	lib/httpd

do-install:
	if [ -f ${WRKSRC}/.libs/libphp${PKG_PHP_VERSION}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp${PKG_PHP_VERSION}.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_VERSION}.so;   \
	elif [ -f ${WRKSRC}/libs/libphp${PKG_PHP_VERSION}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp${PKG_PHP_VERSION}.so  \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_VERSION}.so;   \
	fi

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
