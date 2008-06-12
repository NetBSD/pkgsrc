# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:56 joerg Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.5.2
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-eaccelator-[0-9]*

HOMEPAGE=	http://eaccelerator.net/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
