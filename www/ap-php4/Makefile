# $NetBSD: Makefile,v 1.37 2004/04/24 23:03:25 xtraeme Exp $
#

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache (${PKG_APACHE}) module for PHP4

USE_BUILDLINK3=		YES
APACHE_MODULE=		YES
SHLIBTOOL_OVERRIDE=	libtool

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

.include "../../www/php4/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
