# $NetBSD: Makefile,v 1.9 2007/12/05 17:42:49 ghen Exp $

.include "../../www/ap-fastcgi/Makefile.common"

PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
PKGREVISION=		4
PKG_APACHE_ACCEPTED=	apache2 apache22
APACHE_MANUAL=		manual
APACHE_MODULE=		# defined
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
