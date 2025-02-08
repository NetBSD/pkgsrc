# $NetBSD: Makefile,v 1.61 2025/02/08 03:22:18 taca Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-${PHP_VERSION}
PKGREVISION=		12
COMMENT=		Apache (${PKG_APACHE}) module for ${PHP_PKG_PREFIX}

CONFLICTS=		ap-php-[0-9]*

USE_TOOLS+=		lex pkg-config bison

TOOL_DEPENDS+=		re2c-[0-9]*:../../devel/re2c

APACHE_MODULE=		YES

FORTIFY_SUPPORTED=	no
SSP_SUPPORTED=		no

.include "../../lang/php/phpversion.mk"

.if ${PHP_VER} == 56
USE_TOOLS+=		autoconf269
.else
USE_TOOLS+=		autoconf
.endif

.include "${PHPPKGSRCDIR}/Makefile.php"

# Ensure we export symbols in the linked shared object.
CONFIGURE_ENV+=		EXTRA_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:M*:Q}

INSTALLATION_DIRS=	lib/httpd

pre-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoconf -f

do-install:
	if [ -f ${WRKSRC}/.libs/libphp${PHP_VER}.so ]; then \
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp${PHP_VER}.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PHP_VER}.so; \
	elif [ -f ${WRKSRC}/libs/libphp${PHP_VER}.so ]; then \
		${INSTALL_DATA} ${WRKSRC}/libs/libphp${PHP_VER}.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PHP_VER}.so; \
	elif [ -f ${WRKSRC}/.libs/libphp.so ]; then \
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp.so \
			${DESTDIR}${PREFIX}/lib/httpd/mod_php${PHP_VER}.so; \
	fi

.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
