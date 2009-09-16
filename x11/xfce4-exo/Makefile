# $NetBSD: Makefile,v 1.9 2009/09/16 01:15:35 reed Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.3.101

DISTNAME=	exo-${XFCE4_VERSION}
PKGNAME=	xfce4-exo-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce extension library

DEPENDS+=	p5-URI>=0:../../www/p5-URI

PKGCONFIG_OVERRIDE+=	exo/exo-0.3.pc.in exo-hal/exo-hal-0.3.pc.in

PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}

MAKE_DIRS+=	${SYSCONFDIR}
MAKE_DIRS+=	${EGDIR} ${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
.for f in C es fr id ja pt_BR tr
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/${f}
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/${f}/images
.endfor

CONF_FILES=		${EGDIR}/helpers.rc ${PKG_SYSCONFDIR}/helpers.rc
OWN_DIRS+=		${EGDIR}

PY_PATCHPLIST=		yes

.include "options.mk"

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.4.0

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
