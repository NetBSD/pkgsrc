# $NetBSD: Makefile,v 1.28 2002/10/05 11:22:40 wiz Exp $

DISTNAME=		gnome-python-1.4.0
PKGNAME=		${PYPKGPREFIX}-gnome-1.4.0
PKGREVISION=		2
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gnome-python/}

MAINTAINER=		drochner@netbsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Python Bindings for the GNU Network Object Model Environment

CONFLICTS+=		py-gtk-[0-9]*
CONFLICTS+=		gnome-python-*

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
MAKE_ENV+=		PYINC=${PYINC}
PY_PATCHPLIST=		yes
PYBINMODULE=		yes

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == a.out)
post-configure:
.for DIR in pygtk pygnome
	${MV} ${WRKSRC}/${DIR}/Makefile ${WRKSRC}/${DIR}/Makefile.old
	${SED} -e 's#-Wl,-R#-R#g' ${WRKSRC}/${DIR}/Makefile.old \
	  >${WRKSRC}/${DIR}/Makefile
.endfor
.endif

.include "../../devel/libglade/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
