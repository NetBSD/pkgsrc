# $NetBSD: Makefile,v 1.11 2014/06/10 15:22:17 joerg Exp $

DISTNAME=	mod_fcgid-2.3.9
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/mod_fcgid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/mod_fcgid/
COMMENT=	High performance alternative to mod_cgi or mod_cgid
LICENSE=	apache-2.0

PKG_APACHE_ACCEPTED=	apache22 apache24
APACHE_MODULE=		YES
USE_LIBTOOL=		YES

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure.apxs
CONFIGURE_ENV+=		APXS=${APXS:Q}

MAKE_FLAGS+=		LIBTOOL=${LIBTOOL:Q}
MAKE_FLAGS+=		INCLUDES="-I${BUILDLINK_PREFIX.apache}/include/httpd"

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
