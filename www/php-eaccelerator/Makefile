# $NetBSD: Makefile,v 1.8 2007/12/09 13:59:38 jdolecek Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.5.2
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
