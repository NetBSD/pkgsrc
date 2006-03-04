# $NetBSD: Makefile,v 1.21 2006/03/04 21:31:11 jlam Exp $
#

DISTNAME=	pygtk-0.6.11
PKGNAME=	${PYPKGPREFIX}-gtk-0.6.11
PKGREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/python/v1.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pygtk.org/
COMMENT=	Python Bindings for the GTK Widget Set

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
PY_PATCHPLIST=	yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
