# $NetBSD: Makefile,v 1.16 2005/03/24 11:00:38 wiz Exp $
#

.include "../../x11/gnome-core/Makefile.common"

PKGNAME=		${DISTNAME:S/-core/-session/}
PKGREVISION=		12

COMMENT=		Gnome-session component split out from gnome-core

BUILD_DEPENDS+=		gtk-doc>=0.9:../../textproc/gtk-doc

CONFLICTS+=		gnome-core<1.4.2nb4

USE_DIRS+=		gnome1-1.5

.include "../../mk/bsd.prefs.mk"
.if (${LOCALBASE} == ${X11PREFIX})
BUILDLINK_DEPENDS.gnome-pixmaps=gnome{,2}-pixmaps>=1.4.2
.endif

DISTINFO_FILE=	${.CURDIR}/../../x11/gnome-core/distinfo
PATCHDIR=	${.CURDIR}/../../x11/gnome-core/patches

BUILD_DIRS=	${WRKSRC}/gsm
BUILD_DIRS+=	${WRKSRC}/smproxy

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/gnome-pixmaps/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
