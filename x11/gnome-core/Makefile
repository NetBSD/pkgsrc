# $NetBSD: Makefile,v 1.100 2004/04/26 04:55:28 snj Exp $
#

.include "Makefile.common"

PKGREVISION=		13

COMMENT=		Core component of GNU Network Object Management Environment

DEPENDS+=		xscreensaver-gnome>=4.14:../xscreensaver-gnome
DEPENDS+=		gnome-session>=1.4.2:../../x11/gnome1-session
DEPENDS+=		gnome-panel>=1.4.2:../../x11/gnome1-panel
BUILD_DEPENDS+=		gtk-doc>=0.9:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	YES

CONFLICTS+=		gnome2-terminal-[0-9]*

USE_DIRS+=		gnome1-1.5

.include "../../mk/bsd.prefs.mk"
.if (${LOCALBASE} == ${X11PREFIX})
BUILDLINK_DEPENDS.gnome-pixmaps=gnome{,2}-pixmaps>=1.4.2
.endif

pre-install:
.for dir in gsm smproxy panel applets
	${ECHO} install: >${WRKSRC}/${dir}/Makefile
.endfor

post-install:
.for prg in gnome-feedback gnome-terminal # Handled in gnome-dirs: gpl lgpl fdl
.  for lng in C da de es it no
	[ ! -d ${PREFIX}/share/gnome/help/${prg}/${lng}/figures ] || \
	${RMDIR} ${PREFIX}/share/gnome/help/${prg}/${lng}/figures
.  endfor
.endfor

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
.include "../../x11/gnome1-session/buildlink3.mk"
.include "../../x11/gnome1-panel/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
