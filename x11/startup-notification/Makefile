# $NetBSD: Makefile,v 1.20 2008/11/16 14:01:11 tron Exp $

DISTNAME=		startup-notification-0.9
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/startup-notification/0.9/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		X11 application startup notification library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libstartup-notification-1.0.pc.in

DOCDIR=			${PREFIX}/share/doc/startup-notification
INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/startup-notification
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog NEWS \
		doc/startup-notification.txt \
		${DESTDIR}${DOCDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
