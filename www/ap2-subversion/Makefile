# $NetBSD: Makefile,v 1.59.2.1 2013/10/05 21:04:17 spz Exp $

PKGNAME=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}
PKGREVISION=	2
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--disable-mod-activation
CONFIGURE_ARGS+=	--with-apache-libexecdir

APACHE_MODULE=		YES

BUILD_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

PKG_APACHE_ACCEPTED=	apache2 apache22 apache24

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.if ${PKG_APACHE} == "apache2" && !empty(PKG_BUILD_OPTIONS.subversion-base:Mapr1)
PKG_FAIL_REASON=	"subversion-base package must be built without apr1 option."
.endif
.include "../../mk/bsd.pkg.mk"
