# $NetBSD: Makefile,v 1.9 2004/01/03 18:50:00 reed Exp $
#

DISTNAME=	pygtk-0.6.9
PKGNAME=	${PYPKGPREFIX}-gtk-0.6.9
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/python/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.daa.com.au/~james/pygtk/
COMMENT=	Python Bindings for the GTK Widget Set

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --disable-numpy
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool
PY_PATCHPLIST=	yes
USE_BUILDLINK2=	yes

.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
