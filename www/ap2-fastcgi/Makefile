# $NetBSD: Makefile,v 1.3 2005/05/21 04:10:18 jlam Exp $

.include "../../www/ap-fastcgi/Makefile.common"

PKGNAME=		${DISTNAME:S/mod_/ap2-/}
PKG_APACHE_ACCEPTED=	apache2
APACHE_MANUAL=		manual
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
