# $NetBSD: Makefile,v 1.1.1.1 2002/02/18 11:55:02 drochner Exp $
#

DISTNAME=	pygtk-0.6.9
PKGNAME=	${PYPKGPREFIX}-gtk-0.6.9
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/python/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/pygtk/
COMMENT=	Python Bindings for the GTK Widget Set

DEPENDS+=	gtkglarea-*:../../x11/gtkglarea

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --disable-numpy
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
PY_PATCHPLIST=	yes

.include "../../graphics/imlib/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
