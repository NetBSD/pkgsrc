# $NetBSD: Makefile,v 1.2 1999/11/21 19:53:20 tron Exp $

DISTNAME=	gnome-python-1.0.50
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	py-gtk-*:../py-gtk

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == a.out)
post-configure:
	${MV} ${WRKSRC}/pygnome/Makefile ${WRKSRC}/pygnome/Makefile.old
	${SED} -e 's#-Wl,-R#-R#g' ${WRKSRC}/pygnome/Makefile.old \
	  >${WRKSRC}/pygnome/Makefile
.endif

.include "../../mk/bsd.pkg.mk"
