# $NetBSD: Makefile,v 1.13 2004/05/01 17:57:21 snj Exp $
#

DISTNAME=	pygtk-0.6.9
PKGNAME=	${PYPKGPREFIX}-gtk-0.6.9
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/python/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.daa.com.au/~james/pygtk/
COMMENT=	Python Bindings for the GTK Widget Set

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --disable-numpy
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK3=	yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
