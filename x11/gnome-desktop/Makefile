# $NetBSD: Makefile,v 1.15 2003/12/14 22:42:15 jmmv Exp $
#

DISTNAME=		gnome-desktop-2.4.1.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-desktop/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Common GNOME2 desktop files and libgnome-desktop library

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../graphics/gnome2-pixmaps/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
