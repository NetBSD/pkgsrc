# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:33 tv Exp $
#

DISTNAME=	GTK2-Industrial
PKGNAME=	gtk2-engines-industrial-20030725
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=teams/art.gnome.org/themes/gtk2/}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://art.gnome.org/
COMMENT=	Black and white theme for GTK+ 2.x

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
WRKSRC=			${WRKDIR}/GTK2-Industrial-Engine

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DIRS=		${WRKSRC}/gtk2-engine
INSTALL_DIRS=		${WRKSRC}/gtk2-engine

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
