# $NetBSD: Makefile,v 1.17 2001/04/24 17:27:57 rh Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/12 16:50:43 vanilla Exp
#

DISTNAME=		gtkmm-1.2.5
PKGNAME=		gtk---1.2.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkmm/} \
			${MASTER_SITE_GNOME:=stable/sources/gtkmm/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://gtkmm.sourceforge.net/
COMMENT=		C++ wrapper for the gimp toolkit (gtk++)

BUILD_DEPENDS+=		m4-1.4:../../devel/m4
DEPENDS+=		gtk+>=1.2.7:../../x11/gtk
DEPENDS+=		libsigc++>=1.0.1:../../devel/libsigc++

USE_X11BASE=		YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

M4=			${LOCALBASE}/bin/gm4
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
		${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../mk/bsd.pkg.mk"
