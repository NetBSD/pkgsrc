# $NetBSD: Makefile,v 1.30 2007/06/30 16:09:09 joerg Exp $

PKGNAME=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}
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

.if !empty(PKG_OPTIONS:Mapache22)
BUILDLINK_API_DEPENDS.apache?=	apache>=2.0.48
PKG_APACHE_ACCEPTED=	apache22
.else
PKG_APACHE_ACCEPTED=	apache2
.endif

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
