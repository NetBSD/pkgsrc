# $NetBSD: Makefile,v 1.39 2009/06/01 19:11:58 gdt Exp $

PKGNAME=	${APACHE_PKG_PREFIX}-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../mk/bsd.pkg.mk"
