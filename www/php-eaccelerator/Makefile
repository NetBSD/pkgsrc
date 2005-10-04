# $NetBSD: Makefile,v 1.2 2005/10/04 16:50:50 tv Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.2a
PKGREVISION=	1
CATEGORIES+=	sysutils
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	jdolecek@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
