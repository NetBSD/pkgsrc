# $NetBSD: Makefile,v 1.5 2015/12/19 14:27:15 taca Exp $
#

MODNAME=		uploadprogress
PECL_VERSION=		1.0.3.1
CATEGORIES=		www

MAINTAINER=		mbowie@buzmo.com
COMMENT=		PHP extension to track progress of a file upload

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
