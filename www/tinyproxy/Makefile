# $NetBSD: Makefile,v 1.19 2006/01/05 21:57:36 joerg Exp $
#

DISTNAME=	tinyproxy-1.6.2
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tinyproxy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tinyproxy.sourceforge.net/
COMMENT=	Lightweight HTTP/SSL proxy

GNU_CONFIGURE=	YES

RCD_SCRIPTS=		tinyproxy
PKG_SYSCONFSUBDIR=	tinyproxy

TINYPROXY_USER?=	tinyproxy
TINYPROXY_GROUP?=	tinyproxy
PKG_GROUPS=		${TINYPROXY_GROUP}
PKG_USERS=		${TINYPROXY_USER}:${TINYPROXY_GROUP}::Tinyproxy\ user
FILES_SUBST+=		TINYPROXY_USER=${TINYPROXY_USER:Q}
FILES_SUBST+=		TINYPROXY_GROUP=${TINYPROXY_GROUP:Q}

CONFIGURE_ARGS+=	--with-config=${PKG_SYSCONFDIR}/tinyproxy.conf
CONFIGURE_ARGS+=	--enable-transparent-proxy

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

.include "options.mk"

EGDIR=		${PREFIX}/share/examples/tinyproxy

CONF_FILES=	${EGDIR}/tinyproxy.conf.default ${PKG_SYSCONFDIR}/tinyproxy.conf

SUBST_CLASSES+=		docs
SUBST_FILES.docs=	doc/tinyproxy.8 doc/tinyproxy.conf
SUBST_SED.docs+=	-e 's,@TINYPROXY_USER@,${TINYPROXY_USER},g'
SUBST_SED.docs+=	-e 's,@TINYPROXY_GROUP@,${TINYPROXY_GROUP},g'
SUBST_SED.docs+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.docs=	post-patch

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tinyproxy.conf \
		${EGDIR}/tinyproxy.conf.default
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tinyproxy
	${INSTALL_DATA} ${WRKSRC}/doc/filter-howto.txt \
		${PREFIX}/share/doc/tinyproxy/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
