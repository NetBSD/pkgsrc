# $NetBSD: Makefile,v 1.1.1.1 2007/05/09 10:01:28 tnn Exp $

DISTNAME=		rep-gtk-0.18
PKGNAME=		rep-gtk2-0.18
CATEGORIES=		x11 lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rep-gtk/}

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://rep-gtk.sourceforge.net/
COMMENT=		librep bindings for gtk2 (used by wm/sawfish)

CONFLICTS=		rep-gtk-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/libglade2/buildlink3.mk"
.include "../../lang/librep/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
