# $NetBSD: Makefile,v 1.14 2000/11/11 17:49:28 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/12 16:50:43 vanilla Exp
#

DISTNAME=		gtkmm-1.2.1
PKGNAME=		gtk---1.2.1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkmm/} \
			${MASTER_SITE_GNOME:=stable/sources/gtkmm/}

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://gtkmm.sourceforge.net/

BUILD_DEPENDS+=		gm4:../../devel/m4
DEPENDS+=		gtk+>=1.2.7:../../x11/gtk
DEPENDS+=		libsigc++>=1.0.1:../../devel/libsigc++

USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_PERL5=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

M4=			${LOCALBASE}/bin/gm4
PLIST_SUBST+=		LOCALBASE=${LOCALBASE}

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gtk--.m4 \
		${LOCALBASE}/share/aclocal/gtk--.m4

.include "../../mk/bsd.pkg.mk"
