# $NetBSD: Makefile,v 1.14 2004/07/06 11:28:18 recht Exp $
#

DISTNAME=	pygtk-0.6.11
PKGNAME=	${PYPKGPREFIX}-gtk-0.6.11
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/python/v1.2/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pygtk.org/
COMMENT=	Python Bindings for the GTK Widget Set

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK3=	yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
