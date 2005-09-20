# $NetBSD: Makefile,v 1.4 2005/09/20 18:25:47 tv Exp $

.include "../../www/ap-fastcgi/Makefile.common"

PKGNAME=		${DISTNAME:S/mod_/ap2-/}
PKGREVISION=		1
PKG_APACHE_ACCEPTED=	apache2
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

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
