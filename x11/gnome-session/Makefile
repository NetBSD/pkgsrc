# $NetBSD: Makefile,v 1.43 2004/10/03 00:18:32 tv Exp $
#

DISTNAME=		gnome-session-2.8.0
PKGREVISION=	1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-session/2.8/}
SITES_gnome-splash-2.8.0.1.png=	${MASTER_SITE_LOCAL:=gnome-splash/}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} gnome-splash-2.8.0.1.png

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 session management utilities

CONFLICTS+=		gnome-core<1.4.2nb4

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_PERL5=		build
USE_LIBTOOL=		yes

MAKE_ENV+=		REAL_GCONFTOOL="${GCONFTOOL2}"

CPPFLAGS+=		-DPREFIX=\"\\\"${PREFIX}\\\"\"
CPPFLAGS+=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

GCONF2_SCHEMAS= 	gnome-session.schemas

post-extract:
	${MV} ${WRKSRC}/gnome-session/gnome-splash.png \
	    ${WRKSRC}/gnome-session/gnome-splash-orig.png
	${CP} ${DISTDIR}/gnome-splash-2.8.0.1.png \
	    ${WRKSRC}/gnome-session/gnome-splash.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-session/gnome-splash-orig.png \
	    ${PREFIX}/share/pixmaps/splash/gnome-splash-orig.png

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
