# $NetBSD: Makefile,v 1.19 2001/12/31 23:54:37 jlam Exp $

.include "../../www/php4/Makefile.php"

PKGNAME=		ap-php-${PHP_BASE_VERS}
PKGREVISION=		# empty
COMMENT=		Apache module for PHP4

DEPENDS+=		php>=${PHP_BASE_VERS}:../../www/php4
DEPENDS+=		apache{,6}>=1.3:../../www/apache

# For "apxs":
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

# Ensure we export symbols in the linked shared object.
.if ${OPSYS} != "SunOS"
LDFLAGS+=		-Wl,--export-dynamic
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so	\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
