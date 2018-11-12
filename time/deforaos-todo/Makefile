# $NetBSD: Makefile,v 1.21 2018/11/12 03:53:00 ryoon Exp $

DISTNAME=	Todo-0.2.1
PKGNAME=	deforaos-todo-0.2.1
PKGREVISION=	6
CATEGORIES=	time
MASTER_SITES=	https://www.defora.org/os/download/download/4429/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop todo list

LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/todo.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/todo.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/todo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/todo.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../mail/deforaos-mailer/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
