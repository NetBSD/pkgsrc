# $NetBSD: Makefile,v 1.9 2005/01/15 12:49:31 jmmv Exp $

DISTNAME=		startup-notification-0.7
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/startup-notification/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		X11 application startup notification library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

PKGCONFIG_OVERRIDE=	libstartup-notification-1.0.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/startup-notification/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog NEWS \
		doc/startup-notification.txt \
		${PREFIX}/share/doc/startup-notification/

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
