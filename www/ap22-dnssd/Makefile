# $NetBSD: Makefile,v 1.4 2010/06/13 22:45:32 wiz Exp $
#

DISTNAME=	mod_dnssd-0.5
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/mod_dnssd/
COMMENT=	Apache module which adds Zeroconf support via DNS-SD using Avahi

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-lynx

PKG_APACHE_ACCEPTED=	apache22
APACHE_MODULE_NAME=	mod_dnssd

do-install:
	cd ${WRKSRC}/src && ${APXS} -i -n ${APACHE_MODULE_NAME} \
	    ${APACHE_MODULE_NAME}.la

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
