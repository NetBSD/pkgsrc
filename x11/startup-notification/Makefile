# $NetBSD: Makefile,v 1.1.1.1 2003/04/11 11:25:53 jmmv Exp $

DISTNAME=		startup-notification-0.5
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/startup-notification/0.5/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.gnome.org/
COMMENT=		X11 application startup notification library

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libstartup-notification-1.0.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/startup-notification/
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog NEWS \
		doc/startup-notification.txt \
		${PREFIX}/share/doc/startup-notification/

.include "../../mk/bsd.pkg.mk"
