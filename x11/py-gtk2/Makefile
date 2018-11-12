# $NetBSD: Makefile,v 1.114 2018/11/12 03:51:34 ryoon Exp $

DISTNAME=	pygtk-2.24.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pygtk/gtk2/}
PKGREVISION=	25
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pygtk/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pygtk.org/
COMMENT=	Python bindings for GTK+2
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	${PYPKGPREFIX}-gtk<0.6.10

# IOError: [Errno 2] No such file or directory: 'gtk-types.defs'
MAKE_JOBS_SAFE=	no

USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	pygtk-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=	gmake pkg-config

PY_PATCHPLIST=	YES
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.24.0

REPLACE_PYTHON+=	examples/atk/atk-demo.py
REPLACE_PYTHON+=	examples/glade/autoconnect.py
REPLACE_PYTHON+=	examples/glade/glade-demo.py
REPLACE_PYTHON+=	examples/gtk/customtreemodel.py
REPLACE_PYTHON+=	examples/ide/browse.py
REPLACE_PYTHON+=	examples/ide/edit.py
REPLACE_PYTHON+=	examples/ide/gtkcons.py
REPLACE_PYTHON+=	examples/ide/gtkdb.py
REPLACE_PYTHON+=	examples/ide/gtkprof.py
REPLACE_PYTHON+=	examples/ide/pyide.py
REPLACE_PYTHON+=	examples/pango/extentdemo.py
REPLACE_PYTHON+=	examples/pango/pangocairo-simple.py
REPLACE_PYTHON+=	examples/pango/utf8-demo.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/appwindow.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/buttonbox.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/changedisplay.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/colorsel.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/dialogs.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/dnd.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/editable_cells.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/entry_completion.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/expander.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/hypertext.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/images.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/infobar.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/list_store.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/menu.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/panes.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/pixbufs.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/sizegroup.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/statusicon.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/stock_browser.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/textscroll.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/textview.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/tooltip.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/tree_store.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/treemodel.py
REPLACE_PYTHON+=	examples/pygtk-demo/demos/ui_manager.py
REPLACE_PYTHON+=	examples/pygtk-demo/pygtk-demo.py
REPLACE_PYTHON+=	examples/simple/dnd.py
REPLACE_PYTHON+=	examples/simple/hello.py
REPLACE_PYTHON+=	examples/simple/scribble.py
REPLACE_PYTHON+=	examples/simple/simple.py
REPLACE_PYTHON+=	examples/simple/tooltip.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	tests/runtests.py

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.pygobject+=	${PYPKGPREFIX}-gobject>=2.15.3
.include "../../devel/py-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.16.0
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
