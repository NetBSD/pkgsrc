# $NetBSD: Makefile,v 1.5 2003/05/25 09:17:41 epg Exp $

PKGNAME=	ap2-subversion-${SVNVER}
COMMENT=	WebDAV server (Apache module) for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--disable-mod-activation

APACHE_MODULE=		YES

ALL_TARGET=		apache-mod
INSTALL_TARGET=		install-mods-shared

.include "../../devel/subversion/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
