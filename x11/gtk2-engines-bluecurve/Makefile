# $NetBSD: Makefile,v 1.10 2005/10/02 09:09:31 jmmv Exp $
#

DISTNAME=	GTK2-Wonderland-Engine-1.0
PKGNAME=	gtk2-engines-bluecurve-1.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=teams/art.gnome.org/themes/gtk2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://art.gnome.org/
COMMENT=	Port of the famous Bluecurve theme for GTK2+

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/Bluecurve

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
