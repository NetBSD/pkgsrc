# $NetBSD: Makefile,v 1.13 2004/10/03 00:18:27 tv Exp $
#

DISTNAME=	tinyproxy-1.6.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tinyproxy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tinyproxy.sourceforge.net/
COMMENT=	Lightweight HTTP/SSL proxy

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

RCD_SCRIPTS=		tinyproxy
PKG_SYSCONFSUBDIR=	tinyproxy

TINYPROXY_USER?=	tinyproxy
TINYPROXY_GROUP?=	tinyproxy
PKG_GROUPS=		${TINYPROXY_GROUP}
PKG_USERS=		${TINYPROXY_USER}:${TINYPROXY_GROUP}::Tinyproxy\\ user
FILES_SUBST+=		TINYPROXY_USER="${TINYPROXY_USER}"
FILES_SUBST+=		TINYPROXY_GROUP="${TINYPROXY_GROUP}"

CONFIGURE_ARGS+=	--with-config=${PKG_SYSCONFDIR}/tinyproxy.conf
CONFIGURE_ARGS+=	--enable-transparent-proxy

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

# Socks support
.if defined(USE_SOCKS) && ${USE_SOCKS} == YES
CONFIGURE_ARGS+=        --enable-socks
.endif

EGDIR=		${PREFIX}/share/examples/tinyproxy

CONF_FILES=	${EGDIR}/tinyproxy.conf.default ${PKG_SYSCONFDIR}/tinyproxy.conf

post-patch:
	@cd ${WRKSRC}/doc && \
	for f in tinyproxy.8 tinyproxy.conf; do \
		${MV} $${f} $${f}.orig; \
		${SED} ${FILES_SUBST_SED} $${f}.orig > $${f}; \
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tinyproxy.conf \
		${EGDIR}/tinyproxy.conf.default
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tinyproxy
	${INSTALL_DATA} ${WRKSRC}/doc/filter-howto.txt \
		${PREFIX}/share/doc/tinyproxy/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
