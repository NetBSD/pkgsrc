# $NetBSD: Makefile,v 1.7 2003/08/06 20:25:38 seb Exp $

PKGNAME=	ap2-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES

ALL_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

BUILDLINK_DEPENDS.apache?=	apache>=2.0.47

.include "../../devel/subversion/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
