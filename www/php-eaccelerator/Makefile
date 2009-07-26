# $NetBSD: Makefile,v 1.10 2009/07/26 18:05:03 jdolecek Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.5.3
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-eaccelator-[0-9]*

HOMEPAGE=	http://eaccelerator.net/
# version 0.9.5.3 is not uploaded to sourceforge file repository, so
# temporarily using the primary source
# MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
MASTER_SITES=	http://bart.eaccelerator.net/source/${PECL_VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
