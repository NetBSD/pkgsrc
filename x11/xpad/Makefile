# $NetBSD: Makefile,v 1.80 2023/12/23 09:44:23 zafer Exp $
#

DISTNAME=	xpad-4.8.0
PKGREVISION=	26
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/xpad/trunk/${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mterry.name/xpad/
COMMENT=	Sticky notes application for GTK+ 2.0
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
