# $NetBSD: Makefile,v 1.13 2004/03/26 02:27:56 wiz Exp $

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
