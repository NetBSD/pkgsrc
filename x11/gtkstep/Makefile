# $NetBSD: Makefile,v 1.5 1999/11/22 00:46:50 tron Exp $

DISTNAME=	gtkstep-1.10
CATEGORIES=	x11
MASTER_SITES=	http://ulli.linuxbox.com/gtkstep/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://ulli.linuxbox.com/gtkstep/index.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=  yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../mk/bsd.pkg.mk"
