# $NetBSD: Makefile,v 1.10 2005/12/05 23:55:23 rillig Exp $

DISTNAME=	thy-0.9.4
CATEGORIES=	www
MASTER_SITES=	ftp://bonehunter.rulez.org/pub/thy/stable/

MAINTAINER=	algernon@bonehunter.rulez.org
HOMEPAGE=	http://bonehunter.rulez.org/software/thy/
COMMENT=	Tiny and fast HTTP daemon

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6
USE_PKGINSTALL=		yes
USE_TOOLS+=		bison gmake lex
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	thy
CONF_FILES=		${EGDIR}/thyrc ${PKG_SYSCONFDIR}/thyrc \
			${EGDIR}/http301.html ${PKG_SYSCONFDIR}/http301.html \
			${EGDIR}/http302.html ${PKG_SYSCONFDIR}/http302.html \
			${EGDIR}/http400.html ${PKG_SYSCONFDIR}/http400.html \
			${EGDIR}/http401.html ${PKG_SYSCONFDIR}/http401.html \
			${EGDIR}/http403.html ${PKG_SYSCONFDIR}/http403.html \
			${EGDIR}/http404.html ${PKG_SYSCONFDIR}/http404.html \
			${EGDIR}/http405.html ${PKG_SYSCONFDIR}/http405.html \
			${EGDIR}/http411.html ${PKG_SYSCONFDIR}/http411.html \
			${EGDIR}/http412.html ${PKG_SYSCONFDIR}/http412.html \
			${EGDIR}/http413.html ${PKG_SYSCONFDIR}/http413.html \
			${EGDIR}/http416.html ${PKG_SYSCONFDIR}/http416.html \
			${EGDIR}/http417.html ${PKG_SYSCONFDIR}/http417.html \
			${EGDIR}/http500.html ${PKG_SYSCONFDIR}/http500.html \
			${EGDIR}/http501.html ${PKG_SYSCONFDIR}/http501.html \
			${EGDIR}/http503.html ${PKG_SYSCONFDIR}/http503.html \
			${EGDIR}/http505.html ${PKG_SYSCONFDIR}/http505.html
RCD_SCRIPTS=		thy
INFO_FILES=		thy.info

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
MAKE_FLAGS+=		pkgconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/thy

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/thyrc ${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
