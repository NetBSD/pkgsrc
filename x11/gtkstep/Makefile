# $NetBSD: Makefile,v 1.8 2000/06/21 03:04:36 jlam Exp $

DISTNAME=		gtkstep-1.10
CATEGORIES=		x11
MASTER_SITES=		http://ulli.linuxave.net/gtkstep/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://ulli.linuxave.net/gtkstep/index.html

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${RM} -f ${PREFIX}/share/themes/Step/gtk/gtkrc.in
	${INSTALL_DATA} ${WRKSRC}/step/Theme/gtk/gtkrc \
	  ${PREFIX}/share/themes/Step/gtk

.include "../../mk/bsd.pkg.mk"
