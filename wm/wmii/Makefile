# $NetBSD: Makefile,v 1.23 2011/11/07 11:24:26 wiz Exp $

DISTNAME=		wmii-3.6
PKGREVISION=		4
CATEGORIES=		wm
MASTER_SITES=		http://code.suckless.org/dl/wmii/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://wmii.suckless.org/
COMMENT=		Modular and keyboard-friendly window manager

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		dmenu>=3.7:../../x11/dmenu

USE_TOOLS+=		tbl

NO_CONFIGURE=		yes

BUILD_DEFS+=		PKG_SYSCONFBASE
MAKE_ENV+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}
# parallel compilations of at least cmd/util.o
MAKE_JOBS_SAFE=		no

# see ${WRKSRC}/mk/wmii.mk
CONFVERSION=		3.5
PLIST_SUBST+=		CONFVERSION=${CONFVERSION}

PKG_SYSCONFSUBDIR=	wmii-${CONFVERSION}
EGDIR=			${PREFIX}/share/examples/${PKG_SYSCONFSUBDIR}
EGFILES=		rc.wmii welcome wmiirc
CONF_FILES_MODE=	0755

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

post-build:
	mv ${WRKSRC}/man/wmii.1 ${WRKSRC}/man/wmii.tbl
	${TBL} ${WRKSRC}/man/wmii.tbl > ${WRKSRC}/man/wmii.1

.include "../../devel/libixp/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
