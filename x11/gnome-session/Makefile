# $NetBSD: Makefile,v 1.9 2003/02/14 21:08:38 jmmv Exp $
#

DISTNAME=		gnome-session-2.2.0.2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 session management utilities

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_X11=		yes
USE_PERL5=		build

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--program-transform-name=s,gnome,gnome2,
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

GCONF2_SCHEMAS= 	gnome-session.schemas

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome2-control-center/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
