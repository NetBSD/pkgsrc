# $NetBSD: Makefile,v 1.25 2006/12/08 23:34:11 xtraeme Exp $

PKGNAME=	ap2-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES
PKG_APACHE_ACCEPTED=	apache2 apache22

BUILD_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

BUILDLINK_API_DEPENDS.apache?=	apache>=2.0.48

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
