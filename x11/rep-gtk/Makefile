# $NetBSD: Makefile,v 1.31 2006/02/05 23:11:43 joerg Exp $

DISTNAME=		rep-gtk-0.15
PKGREVISION=		9
CATEGORIES=		x11 lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rep-gtk/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk (used by sawmill)

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

REPEXECDIR=		libexec/rep/${MACHINE_GNU_PLATFORM}
INSTALL_ALIASES=	${PREFIX}/${REPEXECDIR}/install-aliases

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

post-install: fix-libs
	${INSTALL_ALIASES} -c ${FILESDIR} ${PREFIX}/${REPEXECDIR}

# Apparently, librep is a gross abuser of libtool, and breaks most of
# libtool's rules about linking and installing.  Worse yet, it encourages
# users of the library to reuse its libtool abuse.  So we have to whack the
# installed .la files to make them correct as if libtool were *correctly*
# invoked in the first place.
fix-libs:
.for lib in	gdk-pixbuf.la gnome-canvas-pixbuf.la gnome-canvas.la \
		gnomelib.la gnomeui.la gtk.la gui/gnome.la \
		gui/gnome/canvas-pixbuf.la gui/gnome/canvas.la \
		gui/gnome/libglade.la gui/gnome/lib.la gui/gnome/ui.la \
		gui/gtk.la gui/gtk/gdk-pixbuf.la gui/gtk/gtk.la \
		gui/gtk/libglade.la gui/gtk/types.la libglade-gnome.la \
		libglade.la sgtk-types.la
	${SETENV} WRKDIR=${WRKDIR:Q} INSTALL_DATA=${INSTALL_DATA:Q} \
		${SH} ${FILESDIR}/fix-la \
		${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/${lib}
.endfor

.include "../../mk/bsd.pkg.mk"
