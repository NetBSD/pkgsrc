# $NetBSD: Makefile,v 1.6 2004/09/03 12:53:10 jmmv Exp $

DISTNAME=		startup-notification-0.7
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/startup-notification/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.gnome.org/
COMMENT=		X11 application startup notification library

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
