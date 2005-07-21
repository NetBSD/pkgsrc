# $NetBSD: Makefile,v 1.7 2005/07/21 16:30:00 wiz Exp $
#

DISTNAME=	GTK2-Wonderland-Engine-1.0
PKGNAME=	gtk2-engines-bluecurve-1.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=teams/art.gnome.org/themes/gtk2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://art.gnome.org/
COMMENT=	Port of famous Bluecurve theme for GTK2+

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/Bluecurve

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
