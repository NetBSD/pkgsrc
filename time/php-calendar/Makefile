# $NetBSD: Makefile,v 1.3 2025/02/08 03:21:09 taca Exp $

MODNAME=		calendar
PKGREVISION=		1
CATEGORIES+=		time
COMMENT=		PHP extension for calendar conversion support

CONFLICTS=		php-calendar-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
