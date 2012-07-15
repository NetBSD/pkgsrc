# $NetBSD: Makefile,v 1.25 2012/07/15 08:23:00 wiz Exp $

DISTNAME=		startup-notification-0.12
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://www.freedesktop.org/software/startup-notification/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/wiki/Software/startup-notification
COMMENT=		X11 application startup notification library
LICENSE=		mit AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libstartup-notification-1.0.pc.in

DOCDIR=			${PREFIX}/share/doc/startup-notification
INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog NEWS \
		doc/startup-notification.txt ${DESTDIR}${DOCDIR}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
