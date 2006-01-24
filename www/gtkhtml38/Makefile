# $NetBSD: Makefile,v 1.3 2006/01/24 07:32:48 wiz Exp $
#

DISTNAME=	gtkhtml-3.8.1
PKGNAME=	${DISTNAME:S/gtkhtml/gtkhtml38/}
PKGREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkhtml/3.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering/printing/editing engine

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	src/libgtkhtml.pc.in

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
