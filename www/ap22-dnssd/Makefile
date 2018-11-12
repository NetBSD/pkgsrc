# $NetBSD: Makefile,v 1.44 2018/11/12 03:53:03 ryoon Exp $
#

DISTNAME=	mod_dnssd-0.6
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://0pointer.de/lennart/projects/mod_dnssd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/mod_dnssd/
COMMENT=	Apache module which adds Zeroconf support via DNS-SD using Avahi
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

CFLAGS.SunOS+=	-D__EXTENSIONS__	# may be needed for PATH_MAX
CONFIGURE_ENV+=		APXS=${APXS:Q}
CONFIGURE_ARGS+=	--disable-lynx

APACHE_MODULE_NAME=	mod_dnssd
APACHE_MODULE=		yes

INSTALLATION_DIRS+=	lib/httpd

.include "../../mk/apache.mk"

# Avoid conflicting C99 flags.
.if ${PKG_APACHE} == "apache24"
BUILDLINK_TRANSFORM.SunOS+=	rm:-D_XOPEN_SOURCE
BUILDLINK_TRANSFORM.SunOS+=	rm:-D_XOPEN_SOURCE_EXTENDED=1
.endif

do-install:
	cd ${WRKSRC}/src &&						\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&			\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 	\
	      -n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la

.include "../../net/avahi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
