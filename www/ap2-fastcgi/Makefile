# $NetBSD: Makefile,v 1.1.1.1 2004/10/28 21:04:16 cube Exp $

.include "../../www/ap-fastcgi/Makefile.common"

PKGNAME=		${DISTNAME:S/mod_/ap2-/}
PKG_APACHE_ACCEPTED=	apache2
APACHE_MANUAL=		manual

SUBST_CLASSES+=		ap2
SUBST_STAGE.ap2=	pre-build
SUBST_FILES.ap2=	${WRKSRC}/Makefile
SUBST_SED.ap2=		-e s,/usr/local/apache2,${PREFIX}/share/httpd,

post-patch:
	${CP} ${WRKSRC}/Makefile.AP2 ${WRKSRC}/Makefile

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
