# $NetBSD: Makefile,v 1.11 2003/12/06 03:01:58 epg Exp $

PKGNAME=	ap2-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES

ALL_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

BUILDLINK_DEPENDS.apache?=	apache>=2.0.48

.include "../../devel/subversion/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
