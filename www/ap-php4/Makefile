# $NetBSD: Makefile,v 1.15 2001/05/20 05:23:28 jonb Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		ap-php-${PHP_MODULE_VERS}

PHP_PKG_VERS=		# empty
PHP_MODULE_VERS=	${PHP_BASE_VERS}${PHP_PKG_VERS}

COMMENT=		PHP4: Hypertext Preprocessor (Apache module)

DEPENDS+=		php-${PHP_VERS}:../../www/php4
DEPENDS+=		apache{,6}>=1.3:../../www/apache

# For "apxs":
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		-Wl,--export-dynamic

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so 			\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
