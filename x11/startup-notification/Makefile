# $NetBSD: Makefile,v 1.16 2006/02/05 23:11:43 joerg Exp $

DISTNAME=		startup-notification-0.8
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/startup-notification/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		X11 application startup notification library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libstartup-notification-1.0.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/startup-notification
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog NEWS \
		doc/startup-notification.txt \
		${PREFIX}/share/doc/startup-notification/

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
