# $NetBSD: Makefile,v 1.5 2006/06/02 18:28:01 joerg Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.5beta2
PECL_DISTNAME=	${MODNAME}-0.9.5-beta2
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

CONFLICTS=	php-eaccelator-[0-9]

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
