# $NetBSD: Makefile,v 1.1.1.1 2009/04/16 19:06:56 drochner Exp $
#

DISTNAME=	xdg-user-dirs-0.10
CATEGORIES=	x11
MASTER_SITES=	http://user-dirs.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/xdg-user-dirs
COMMENT=	Tool to manage "well known" user directories

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

EGDIR=	${PREFIX}/share/examples/xdg

CONF_FILES+=	${EGDIR}/user-dirs.conf \
		${PKG_SYSCONFDIR}/xdg/user-dirs.conf
CONF_FILES+=	${EGDIR}/user-dirs.defaults \
		${PKG_SYSCONFDIR}/xdg/user-dirs.defaults

.include "../../mk/bsd.pkg.mk"
