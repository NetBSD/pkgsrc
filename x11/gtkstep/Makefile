# $NetBSD: Makefile,v 1.15 2004/03/08 19:40:45 jmmv Exp $

DISTNAME=		gtkstep-1.10
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		http://ulli.linuxave.net/gtkstep/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://ulli.linuxave.net/gtkstep/index.html
COMMENT=		GTK theme-engine to yield a NEXTSTEP(tm) look and feel

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
