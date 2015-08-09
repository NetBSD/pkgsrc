# $NetBSD: Makefile,v 1.12 2015/08/09 15:22:22 khorben Exp $
#

DISTNAME=	Todo-0.1.2
PKGNAME=	deforaos-todo-0.1.2
PKGREVISION=	9
CATEGORIES=	time
MASTER_SITES=	http://www.defora.org/os/download/download/3506/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop todo list

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
