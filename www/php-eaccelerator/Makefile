# $NetBSD: Makefile,v 1.7 2006/11/06 20:58:50 jdolecek Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.5
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

CONFLICTS=	php-eaccelator-[0-9]*

HOMEPAGE=	http://eaccelerator.net/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
