# $NetBSD: Makefile,v 1.6 2000/04/24 16:02:33 mbw Exp $

DISTNAME=	gtkstep-1.10
CATEGORIES=	x11
MASTER_SITES=	http://ulli.linuxave.net/gtkstep/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://ulli.linuxave.net/gtkstep/index.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=  yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../mk/bsd.pkg.mk"
