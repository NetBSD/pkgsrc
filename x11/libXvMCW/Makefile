# $NetBSD: Makefile,v 1.1.1.1 2011/01/19 00:42:12 jmcneill Exp $
#

DISTNAME=	libXvMCW-0.9.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unichrome/}XvMC%20Wrapper/release-0.9.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unichrome.sourceforge.net/
COMMENT=	Wrapper for run-time loading of XvMC libraries
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

EGDIR=		${PREFIX}/share/examples/libXvMCW
CONF_FILES=	${EGDIR}/XvMCConfig ${PKG_SYSCONFDIR}/XvMCConfig

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${EGDIR}
CONFIGURE_ARGS+=	--with-config-path=${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/XvMCConfig ${DESTDIR}${EGDIR}

.include "../../x11/libXvMC/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
