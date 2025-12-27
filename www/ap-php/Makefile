# $NetBSD: Makefile,v 1.64 2025/12/27 19:04:48 gutteridge Exp $

PKGNAME=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-${PHP_VERSION}
PKGREVISION=		13
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

.include "../../mk/compiler.mk"

# Needed for PHP 5.6 with GCC >= 14 on NetBSD.
.if ${PKGSRC_COMPILER:Mgcc}
CFLAGS+=	-Wno-error=incompatible-pointer-types -Wno-error=int-conversion
.endif

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
