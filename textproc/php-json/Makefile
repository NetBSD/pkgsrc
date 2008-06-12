# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:51 joerg Exp $

MODNAME=		json
PECL_VERSION=		1.2.1
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
