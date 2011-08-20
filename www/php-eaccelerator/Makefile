# $NetBSD: Makefile,v 1.14 2011/08/20 14:19:35 taca Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.6.1
CATEGORIES+=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/} \
		http://bart.eaccelerator.net/source/${PECL_VERSION}/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://sourceforge.net/projects/eaccelerator/
MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-eaccelator-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
