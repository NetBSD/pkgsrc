# $NetBSD: Makefile,v 1.30 2005/06/19 08:07:05 wiz Exp $

DISTNAME=	dillo-0.8.5
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://www.dillo.org/
COMMENT=	Very small and fast graphical web-browser

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/dillo
CONF_FILES=	${EGDIR}/dillorc.default ${PKG_SYSCONFDIR}/dillorc
CONF_FILES+=	${EGDIR}/dpidrc ${PKG_SYSCONFDIR}/dpidrc

PKG_OPTIONS_VAR=	PKG_OPTIONS.dillo
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/dillo
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dillorc ${EGDIR}/dillorc.default

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
