# $NetBSD: Makefile,v 1.18 2004/12/03 15:15:12 wiz Exp $

PKGNAME=	ap2-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES

BUILD_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

BUILDLINK_DEPENDS.apache?=	apache>=2.0.48

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
