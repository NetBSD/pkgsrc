# $NetBSD: Makefile,v 1.1.1.1 2009/03/16 08:38:37 jmcneill Exp $
#

DISTNAME=	murrine-0.90.0
PKGNAME=	${DISTNAME:S/^/gtk2-engines-/}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/murrine/0.90/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cimitan.com/murrine/
COMMENT=	GTK2+ engine featuring a modern glassy look

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake pkg-config intltool
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-animation

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
