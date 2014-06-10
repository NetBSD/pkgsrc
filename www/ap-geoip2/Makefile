# $NetBSD: Makefile,v 1.4 2014/06/10 15:22:15 joerg Exp $
#

DISTNAME=	mod_geoip2_1.2.5
PKGNAME=	${DISTNAME:S/mod_/${APACHE_PKG_PREFIX}-/:S/_/-/}
CATEGORIES=	www
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/mod_geoip2/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.maxmind.com/app/mod_geoip
COMMENT=	Apache module to interact with the MaxMind geoip database
LICENSE=	apache-1.1

.include "../../mk/apache.mk"
APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_geoip.so
PKG_APACHE_ACCEPTED=	apache22
NO_CONFIGURE=	yes
CPPFLAGS+=	-I${DESTDIR}/include
LDFLAGS+=	-L${DESTDIR}/lib -lGeoIP

pre-install:
	cp ${WRKDIR}/${DISTNAME}/.libs/mod_geoip.so ${WRKDIR}/${DISTNAME}/

.include "../../www/apache/module.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
