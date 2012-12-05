# $NetBSD: Makefile,v 1.20 2012/12/05 15:28:30 taca Exp $

MODNAME=	eaccelerator
PKGREVISION=	1
PECL_VERSION=	0.9.6.1
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=eaccelerator/} \
		http://bart.eaccelerator.net/source/${PECL_VERSION}/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://github.com/eaccelerator/eaccelerator
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP accelerator, optimizer, encoder and dynamic content cache
LICENSE=	gnu-gpl-v2

PHP_VERSIONS_ACCEPTED=	53

CONFLICTS=		php-eaccelator-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "options.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
