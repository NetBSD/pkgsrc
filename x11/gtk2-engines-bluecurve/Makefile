# $NetBSD: Makefile,v 1.47 2018/11/12 03:53:08 ryoon Exp $
#

DISTNAME=	GTK2-Wonderland-Engine-1.0
PKGNAME=	gtk2-engines-bluecurve-1.0
PKGREVISION=	33
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=teams/art.gnome.org/themes/gtk2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://art.gnome.org/
COMMENT=	Port of the famous Bluecurve theme for GTK2+

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/Bluecurve

SHLIBTOOL_OVERRIDE=	# empty

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
