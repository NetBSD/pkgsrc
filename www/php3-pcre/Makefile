# $NetBSD: Makefile,v 1.1.1.1 2001/06/07 16:28:27 jlam Exp $
#
# This package is a placeholder to signify that the base PHP3 package already
# has the PCRE functionality.  It *must* have the same version number as the
# PHP3 package.
#
DISTNAME=		php-pcre-${PHP_VERSION}
PHP_VERSION=		3.0.18
CATEGORIES=		www
DISTFILES=		# empty

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP3 extension for Perl-compatible regular expressions

DEPENDS+=		php-${PHP_VERSION}:../../www/php3

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
