# $NetBSD: Makefile,v 1.43 2004/10/03 00:18:32 tv Exp $

DISTNAME=		gnome-python-1.4.4
PKGNAME=		${PYPKGPREFIX}-gnome-1.4.4
PKGREVISION=		6
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-python/1.4/}

MAINTAINER=		drochner@NetBSD.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Python Bindings for the GNU Network Object Model Environment

BUILDLINK_DEPENDS.gnome-panel=	gnome-panel<2.0

CONFLICTS+=		py-gtk-[0-9]*
CONFLICTS+=		gnome-python-*

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
MAKE_ENV+=		PYINC=${PYINC}
PY_PATCHPLIST=		yes
PYBINMODULE=		yes

.include "../../mk/bsd.prefs.mk"

# XXX This doesn't quite work if _USE_RPATH=no.
.if (${OBJECT_FMT} == a.out)
post-configure:
.for DIR in pygtk pygnome
	${MV} ${WRKSRC}/${DIR}/Makefile ${WRKSRC}/${DIR}/Makefile.old
	${SED} -e 's#-Wl,-R#${LINKER_RPATH_FLAG} #g' \
		${WRKSRC}/${DIR}/Makefile.old >${WRKSRC}/${DIR}/Makefile
.endfor
.endif

.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
