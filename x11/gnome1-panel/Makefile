# $NetBSD: Makefile,v 1.6 2003/11/12 01:31:52 salo Exp $
#

.include "../../x11/gnome-core/Makefile.common"

PKGNAME=		${DISTNAME:S/-core/-panel/}
PKGREVISION=		3

COMMENT=		Gnome-panel component split out from gnome-core

DEPENDS+=		gnome1-dirs>=1.0:../../misc/gnome1-dirs
DEPENDS+=		gnome-session>=1.4.2:../../x11/gnome1-session
DEPENDS+=		xscreensaver-gnome>=3.25nb1:../xscreensaver-gnome
BUILD_DEPENDS+=		gtk-doc>=0.9:../../textproc/gtk-doc

CONFLICTS+=		gnome-core<1.4.2nb4

.include "../../mk/bsd.prefs.mk"
.if (${LOCALBASE} == ${X11PREFIX})
BUILDLINK_DEPENDS.gnome-pixmaps=gnome{,2}-pixmaps>=1.4.2
.endif

DISTINFO_FILE=	${.CURDIR}/../../x11/gnome-core/distinfo
PATCHDIR=	${.CURDIR}/../../x11/gnome-core/patches

BUILD_DIRS=	${WRKSRC}/panel
BUILD_DIRS+=	${WRKSRC}/applets

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/gnome-pixmaps/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
