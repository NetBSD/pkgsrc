# $NetBSD: Makefile,v 1.31 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=		gnome-session-2.4.2
PKGREVISION=		3
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 session management utilities

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

CONFLICTS+=		gnome-core<1.4.2nb4

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_PERL5=		build
USE_LIBTOOL=		yes

GCONF2_SCHEMAS= 	gnome-session.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
