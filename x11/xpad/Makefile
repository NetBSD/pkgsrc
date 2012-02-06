# $NetBSD: Makefile,v 1.37 2012/02/06 12:42:31 wiz Exp $
#

DISTNAME=	xpad-4.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/xpad/trunk/${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mterry.name/xpad/
COMMENT=	Sticky notes application for GTK+ 2.0
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
