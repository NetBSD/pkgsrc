# $NetBSD: Makefile,v 1.3 2009/07/07 17:54:26 joerg Exp $
#

DISTNAME=	xdg-user-dirs-0.10
CATEGORIES=	x11
MASTER_SITES=	http://user-dirs.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/xdg-user-dirs
COMMENT=	Tool to manage "well known" user directories

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

EGDIR=	${PREFIX}/share/examples/xdg

CONF_FILES+=	${EGDIR}/user-dirs.conf \
		${PKG_SYSCONFDIR}/xdg/user-dirs.conf
CONF_FILES+=	${EGDIR}/user-dirs.defaults \
		${PKG_SYSCONFDIR}/xdg/user-dirs.defaults

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
