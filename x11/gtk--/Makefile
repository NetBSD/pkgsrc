# $NetBSD: Makefile,v 1.21 2001/11/30 17:54:39 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/12 16:50:43 vanilla Exp
#

DISTNAME=		gtkmm-1.2.5
PKGNAME=		gtk---1.2.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkmm/} \
			${MASTER_SITE_GNOME:=stable/sources/gtkmm/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ wrapper for GTK+

BUILD_DEPENDS+=		m4>=1.4:../../devel/m4

USE_X11BASE=		YES

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

M4=			${LOCALBASE}/bin/gm4
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
		${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../devel/libsigc++/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
