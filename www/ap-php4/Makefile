# $NetBSD: Makefile,v 1.16 2001/10/16 04:54:23 jlam Exp $

.include "../php4/Makefile.php"

PKGNAME=		ap-php-${PHP_VERS}
PHP_PKG_VERS=		# empty
COMMENT=		Apache module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../php4
DEPENDS+=		apache{,6}>=1.3:../../www/apache

# For "apxs":
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		-Wl,--export-dynamic

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
