# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:24 tv Exp $

PKGNAME=	ap2-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES

ALL_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

BUILDLINK_DEPENDS.apache?=	apache>=2.0.48

.include "../../devel/subversion/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
