# $NetBSD: Makefile,v 1.25 2002/09/11 21:53:46 wiz Exp $
#

DISTNAME=		gtkmm-1.2.10
PKGNAME=		gtk---1.2.10
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkmm/} \
			${MASTER_SITE_GNOME:=stable/sources/gtkmm/}

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
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig
CONFIGURE_ARGS=		--enable-static

M4=			${LOCALBASE}/bin/gm4
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
		${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
