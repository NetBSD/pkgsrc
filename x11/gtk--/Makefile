# $NetBSD: Makefile,v 1.34 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=		gtkmm-1.2.10
PKGNAME=		gtk---1.2.10
PKGREVISION=		3
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkmm/} \
			${MASTER_SITE_GNOME:=sources/gtkmm/1.2/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ wrapper for GTK+

USE_X11BASE=		YES

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build
USE_GNU_TOOLS+=		m4 make
USE_LIBTOOL=		YES
CONFIGURE_ARGS=		--enable-static

PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
		${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
