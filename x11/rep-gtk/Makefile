# $NetBSD: Makefile,v 1.26 2004/10/03 00:18:38 tv Exp $

DISTNAME=		rep-gtk-0.15
PKGREVISION=		6
CATEGORIES=		x11 lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rep-gtk/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk (used by sawmill)

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PLIST_SRC=		${WRKDIR}/.PLIST_SRC
REPEXECDIR=		libexec/rep/${MACHINE_GNU_PLATFORM}
INSTALL_ALIASES=	${PREFIX}/${REPEXECDIR}/install-aliases

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

post-install:
	${INSTALL_ALIASES} -c ${FILESDIR} ${PREFIX}/${REPEXECDIR}
	${RM} -f ${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ${REPEXECDIR}				\
		-name "gnomelib.*" -print > ${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ${REPEXECDIR}/gui/gnome			\
		-name "lib.*" -print >> ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
