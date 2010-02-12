# $NetBSD: Makefile,v 1.20 2010/02/12 20:34:16 joerg Exp $
#

DISTNAME=	windowlab-1.33
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake pkg-config

EGDIR=		${PREFIX}/share/examples/windowlab
CONF_FILES=	${EGDIR}/windowlab.menurc ${PKG_SYSCONFDIR}/windowlab.menurc

INSTALLATION_DIRS=	share/examples/windowlab

post-install:
	${INSTALL_DATA} ${WRKSRC}/windowlab.menurc ${DESTDIR}${EGDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
