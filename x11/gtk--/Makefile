# $NetBSD: Makefile,v 1.30 2003/05/05 14:41:58 jmmv Exp $
#

DISTNAME=		gtkmm-1.2.10
PKGNAME=		gtk---1.2.10
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkmm/} \
			${MASTER_SITE_GNOME:=sources/gtkmm/1.2/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ wrapper for GTK+

BUILD_DEPENDS+=		m4>=1.4:../../devel/m4

USE_X11BASE=		YES

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS=		--enable-static

M4=			${LOCALBASE}/bin/gm4
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
		${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
