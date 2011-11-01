# $NetBSD: Makefile,v 1.51 2011/11/01 06:02:45 sbd Exp $

DISTNAME=	dillo-2.2
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dillo.org/
COMMENT=	Very small and fast graphical web-browser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

REPLACE_PERL+=	dpid/dpidc
USE_TOOLS+=	perl:run

DEPENDS+=	wget-[0-9]*:../../net/wget

PKG_SYSCONFSUBDIR=	dillo
EGDIR=		${PREFIX}/share/examples/dillo
CONF_FILES=	${EGDIR}/dillorc ${PKG_SYSCONFDIR}/dillorc
CONF_FILES+=	${EGDIR}/dpidrc ${PKG_SYSCONFDIR}/dpidrc
CONF_FILES+=	${EGDIR}/keysrc ${PKG_SYSCONFDIR}/keysrc

INSTALLATION_DIRS=	share/doc/dillo ${EGDIR}

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/README ${DESTDIR}${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/dillorc ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/keysrc ${DESTDIR}${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
