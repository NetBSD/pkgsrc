# $NetBSD: Makefile,v 1.1.1.1 2002/10/17 09:56:52 martti Exp $

PKGNAME=		ap2-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4

USE_BUILDLINK2=		YES
APACHE_MODULE=		YES

CONFIGURE_ARGS+=	--with-tsrm-pth

.include "../../www/php4/Makefile.php"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../www/apache2/buildlink2.mk"
.include "../../devel/pth/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
