# $NetBSD: Makefile,v 1.18 2001/05/19 14:49:48 drochner Exp $

DISTNAME=		gnome-python-1.4.0
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-python/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Python Bindings for the GNU Network Object Model Environment

DEPENDS+=		gnome-core>1.4.0:../gnome-core
DEPENDS+=		gtkglarea-*:../../x11/gtkglarea
DEPENDS+=		libglade-*:../../devel/libglade
DEPENDS+=		python>=2.0:../../lang/python

CONFLICTS+=		py-gtk-*

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == a.out)
post-configure:
.for DIR in pygtk pygnome
	${MV} ${WRKSRC}/${DIR}/Makefile ${WRKSRC}/${DIR}/Makefile.old
	${SED} -e 's#-Wl,-R#-R#g' ${WRKSRC}/${DIR}/Makefile.old \
	  >${WRKSRC}/${DIR}/Makefile
.endfor
.endif

.include "../../mk/bsd.pkg.mk"
