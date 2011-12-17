# $NetBSD: Makefile,v 1.2 2011/12/17 13:46:29 obache Exp $
#

MODNAME=		uploadprogress
PECL_VERSION=		1.0.1
CATEGORIES=		www

MAINTAINER=		mbowie@buzmo.com
COMMENT=		PHP extension to track progress of a file upload

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
