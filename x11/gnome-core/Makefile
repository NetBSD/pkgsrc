# $NetBSD: Makefile,v 1.94 2003/12/13 19:46:46 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		9

COMMENT=		Core component of GNU Network Object Management Environment

DEPENDS+=		gnome1-dirs>=1.0:../../misc/gnome1-dirs
DEPENDS+=		xscreensaver-gnome>=4.14:../xscreensaver-gnome
DEPENDS+=		gnome-session>=1.4.2:../../x11/gnome1-session
DEPENDS+=		gnome-panel>=1.4.2:../../x11/gnome1-panel
BUILD_DEPENDS+=		gtk-doc>=0.9:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	YES

CONFLICTS+=		gnome2-terminal-[0-9]*

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
.include "../../x11/gnome1-session/buildlink2.mk"
.include "../../x11/gnome1-panel/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
