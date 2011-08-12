# $NetBSD: Makefile,v 1.25 2011/08/12 12:24:52 taca Exp $
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
CONFIGURE_ENV+=	EXTRA_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:M*:Q}

INSTALLATION_DIRS=	lib/httpd

do-install:
	if [ -f ${WRKSRC}/.libs/libphp${PKG_PHP_MAJOR_VERS}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp${PKG_PHP_MAJOR_VERS}.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_MAJOR_VERS}.so;   \
	elif [ -f ${WRKSRC}/libs/libphp${PKG_PHP_MAJOR_VERS}.so ]; then	\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp${PKG_PHP_MAJOR_VERS}.so  \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PKG_PHP_MAJOR_VERS}.so;   \
	fi

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
