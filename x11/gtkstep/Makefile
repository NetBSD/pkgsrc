# $NetBSD: Makefile,v 1.18 2004/04/24 22:46:13 jlam Exp $

DISTNAME=		gtkstep-1.10
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		http://ulli.linuxave.net/gtkstep/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ulli.linuxave.net/gtkstep/index.html
COMMENT=		GTK theme-engine to yield a NEXTSTEP(tm) look and feel

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
