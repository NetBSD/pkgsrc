# $NetBSD: Makefile,v 1.42 2008/10/31 02:02:44 snj Exp $

DISTNAME=	dillo-2.0
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dillo.org/
COMMENT=	Very small and fast graphical web-browser

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

REPLACE_PERL+=	dpid/dpidc
USE_TOOLS+=	perl:run

DEPENDS+=	wget-[0-9]*:../../net/wget

EGDIR=		${PREFIX}/share/examples/dillo
CONF_FILES=	${EGDIR}/dillorc ${PKG_SYSCONFDIR}/dillorc
CONF_FILES+=	${EGDIR}/dpidrc ${PKG_SYSCONFDIR}/dpidrc

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/dillo
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dillorc ${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/fltk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
