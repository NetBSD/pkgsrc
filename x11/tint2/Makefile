# $NetBSD: Makefile,v 1.2 2009/12/15 22:18:09 joerg Exp $

DISTNAME=		tint2-0.7.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://tint2.googlecode.com/files/

MAINTAINER=		fernandotcl@gmail.com
HOMEPAGE=		http://tint2.googlecode.com/files/
COMMENT=		Tint2 is a simple panel/taskbar
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKG_SYSCONFSUBDIR=	xdg

OWN_DIRS=		${PKG_SYSCONFDIR}/tint2
CONF_FILES=		${PREFIX}/share/examples/tint2/tint2rc \
			${PKG_SYSCONFDIR}/tint2/tint2rc

INSTALLATION_DIRS=	share/examples/tint2

post-install:
	${INSTALL_DATA} ${WRKSRC}/tint2rc \
		${DESTDIR}${PREFIX}/share/examples/tint2

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
