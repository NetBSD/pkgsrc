# $NetBSD: Makefile,v 1.23 2006/03/04 21:31:09 jlam Exp $

DISTNAME=		gtkstep-1.10
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		http://ulli.linuxave.net/gtkstep/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ulli.linuxave.net/gtkstep/index.html
COMMENT=		GTK theme-engine to yield a NEXTSTEP(tm) look and feel

USE_DIRS+=		xdg-1.1
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
