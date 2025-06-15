# $NetBSD: Makefile,v 1.1 2025/06/15 14:05:48 ryoon Exp $

DISTNAME=	mod_qos-11.76
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-qos/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://mod-qos.sourcweforge.net/
COMMENT=	Quality of service Apache module
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/tools

APACHE_MODULE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	lib/httpd

post-build:
	cd ${WRKDIR}/${DISTNAME}/apache2 && \
		${LOCALBASE}/bin/apxs -c mod_qos.c -lcrypto -lpcre2-8

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKDIR}/${DISTNAME}/apache2/mod_qos.la \
		${DESTDIR}${PREFIX}/lib/httpd

.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
