# $NetBSD: Makefile,v 1.12 2018/11/14 22:22:42 kleink Exp $

DISTNAME=	unico-1.0.2
PKGNAME=	gtk3-engines-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/unico/1.0/1.0.2/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/unico
COMMENT=	Unico Gtk+ Theming Engine for GTK+ 3.0
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
