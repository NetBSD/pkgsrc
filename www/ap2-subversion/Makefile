# $NetBSD: Makefile,v 1.26 2007/01/25 07:35:30 epg Exp $

PKGNAME=	ap2-subversion-${SVNVER}
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
PKG_APACHE_ACCEPTED=		apache22
.else
PKG_APACHE_ACCEPTED=		apache2
.endif

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
