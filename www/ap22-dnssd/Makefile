# $NetBSD: Makefile,v 1.17.2.1 2012/10/03 12:09:42 spz Exp $
#

DISTNAME=	mod_dnssd-0.5
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=	14
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/mod_dnssd/
COMMENT=	Apache module which adds Zeroconf support via DNS-SD using Avahi

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

CONFIGURE_ENV+=		APXS=${APXS:Q}
CONFIGURE_ARGS+=	--disable-lynx

PKG_APACHE_ACCEPTED=	apache22
APACHE_MODULE_NAME=	mod_dnssd

INSTALLATION_DIRS+=	lib/httpd

do-install:
	cd ${WRKSRC}/src &&						\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&			\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 	\
	      -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
