# $NetBSD: Makefile,v 1.13 2007/01/15 11:39:10 ghen Exp $
#

DISTNAME=		wmii-3.1
CATEGORIES=		wm
MASTER_SITES=		http://suckless.org/download/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Modular and keyboard-friendly window manager

NO_CONFIGURE=		yes

BUILD_DEFS+=		PKG_SYSCONFBASE

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	cmd/wm/wmii rc/wmiirc cmd/wm/wmii.1
SUBST_SED.path+=	-e 's|CONFPREFIX|${PKG_SYSCONFBASE}|g'

PKG_SYSCONFSUBDIR=	wmii-3
EGDIR=			${PREFIX}/share/examples/${PKG_SYSCONFSUBDIR}
EGFILES=		quit status welcome wmiirc
CONF_FILES_MODE=	0755

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
