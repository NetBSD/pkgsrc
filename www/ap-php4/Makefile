# $NetBSD: Makefile,v 1.33 2003/11/22 08:24:40 grant Exp $
#

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache (${PKG_APACHE}) module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../www/php4/Makefile.php"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	if [ -f ${WRKSRC}/.libs/libphp4.so ]; then		\
		${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
			${PREFIX}/lib/httpd/mod_php4.so;	\
	elif [ -f ${WRKSRC}/libs/libphp4.so ]; then		\
		${INSTALL_DATA} ${WRKSRC}/libs/libphp4.so	\
			${PREFIX}/lib/httpd/mod_php4.so;	\
	fi	


.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
