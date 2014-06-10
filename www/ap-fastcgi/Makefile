# $NetBSD: Makefile,v 1.33 2014/06/10 15:22:15 joerg Exp $

DISTNAME=	mod_fastcgi-2.4.6
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	New, improved CGI-like interface module for Apache

PLIST_SUBST+=	APACHE_MANUAL=${APACHE_MANUAL:Q}
MESSAGE_SUBST+=	APACHE_MANUAL=${APACHE_MANUAL:Q}

INSTALLATION_DIRS+=	share/httpd/${APACHE_MANUAL}/mod

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html	\
		${DESTDIR}${PREFIX}/share/httpd/${APACHE_MANUAL}/mod/

PKG_APACHE_ACCEPTED=	apache22
APACHE_MANUAL=		manual
APACHE_MODULE=		YES
USE_LIBTOOL=		YES

MAKE_FLAGS+=		LIBTOOL=${LIBTOOL:Q}

SUBST_CLASSES+=		ap2
SUBST_STAGE.ap2=	pre-build
SUBST_FILES.ap2=	Makefile
SUBST_SED.ap2=		-e s,/usr/local/apache2,${PREFIX}/share/httpd,

post-patch:
	${CP} ${WRKSRC}/Makefile.AP2 ${WRKSRC}/Makefile

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
