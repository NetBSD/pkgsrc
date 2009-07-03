# $NetBSD: Makefile,v 1.20 2009/07/03 11:01:01 drochner Exp $

DISTNAME=	thy-0.9.4
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	ftp://bonehunter.rulez.org/pub/thy/stable/

MAINTAINER=	algernon@bonehunter.rulez.org
HOMEPAGE=	http://bonehunter.rulez.org/software/thy/
COMMENT=	Tiny and fast HTTP daemon

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=		IPV6_READY
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
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
MAKE_FLAGS+=		pkgconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/thy
INSTALLATION_DIRS=	share/examples/thy

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/thyrc ${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../security/gnutls/libgnutls-extra-config.mk"
.include "../../mk/bsd.pkg.mk"
