# $NetBSD: Makefile,v 1.19 2014/12/28 15:12:22 mef Exp $
#

DISTNAME=		matchbox-window-manager-1.1
PKGNAME=		${DISTNAME:S/window-manager/wm/}
PKGREVISION=		7
CATEGORIES=		wm x11
MASTER_SITES=		http://downloads.yoctoproject.org/releases/matchbox/matchbox-window-manager/1.1/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.yoctoproject.org/tools-resources/projects/matchbox
COMMENT=		Window manager designed for computers with small displays

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

PKG_SYSCONFSUBDIR=	matchbox
EGDIR=			${PREFIX}/share/examples/matchbox
CONF_FILES=		${EGDIR}/kbdconfig ${PKG_SYSCONFDIR}/kbdconfig

INSTALLATION_DIRS+=	share/examples/matchbox

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/kbdconfig \
		${DESTDIR}${PREFIX}/share/examples/matchbox/

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
