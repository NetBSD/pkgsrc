# $NetBSD: Makefile,v 1.1.1.1 2005/05/07 18:53:33 jdolecek Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.2a
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
