# $NetBSD: Makefile,v 1.10 2001/10/22 02:27:38 mycroft Exp $
#

DISTNAME=		rep-gtk-0.15
CATEGORIES=		x11 lang
MASTER_SITES=		http://prdownloads.sourceforge.net/rep-gtk/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk (used by sawmill)

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		librep>=0.15:../../lang/librep
DEPENDS+=		libglade-[0-9]*:../../devel/libglade
DEPENDS+=		gnome-libs-[0-9]*:../../x11/gnome-libs
DEPENDS+=		gdk-pixbuf-gnome>=0.9.0:../../graphics/gdk-pixbuf-gnome

USE_X11=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
REPEXECDIR=		${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}
INSTALL_ALIASES=	${REPEXECDIR}/install-aliases

post-install:
	${INSTALL_ALIASES} -c ${FILESDIR} ${REPEXECDIR}
	${RM} -f ${PLIST_SRC}
	cd ${PREFIX} && ${FIND} libexec/rep/${MACHINE_GNU_PLATFORM} \
		-name "gnomelib.*" > ${PLIST_SRC}
	cd ${PREFIX} && ${FIND} libexec/rep/${MACHINE_GNU_PLATFORM}/gui/gnome \
		-name "lib.*" >> ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
