# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:33 tv Exp $
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
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/Bluecurve

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
