# $NetBSD: Makefile,v 1.3 2002/11/02 02:42:06 rh Exp $
#

DISTNAME=		gnome-session-2.0.7
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 session management utilities

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11=		yes
USE_PERL5=		build

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--program-transform-name=s,gnome,gnome2,
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gnome2-control-center/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
