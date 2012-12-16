# $NetBSD: Makefile,v 1.52 2012/12/16 01:52:37 obache Exp $

PKGNAME=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}
PKGREVISION=	5
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES

BUILD_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.if ${PKG_APACHE} == "apache2" && !empty(PKG_BUILD_OPTIONS.subversion-base:Mapr1)
PKG_FAIL_REASON=	"subversion-base package must be built without apr1 option."
.endif
.include "../../mk/bsd.pkg.mk"
