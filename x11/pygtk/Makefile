# $NetBSD: Makefile,v 1.3 2002/09/21 23:47:02 jlam Exp $
#

DISTNAME=	pygtk-0.6.9
PKGNAME=	${PYPKGPREFIX}-gtk-0.6.9
PKGREVISION=	1
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
.include "../../lang/python/extension.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
