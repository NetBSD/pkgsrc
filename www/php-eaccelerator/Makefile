# $NetBSD: Makefile,v 1.18 2012/06/16 22:34:23 dholland Exp $

MODNAME=	eaccelerator
PECL_VERSION=	0.9.6.1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/} \
		http://bart.eaccelerator.net/source/${PECL_VERSION}/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://sourceforge.net/projects/eaccelerator/
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PHP_VERSIONS_ACCEPTED=	53

CONFLICTS=		php-eaccelator-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
