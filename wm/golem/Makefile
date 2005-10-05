# $NetBSD: Makefile,v 1.15 2005/10/05 13:29:49 wiz Exp $
#

DISTNAME=	golem-0.0.5
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golem/}

MAINTAINER=	reide@darkest.org
HOMEPAGE=	http://golem.sourceforge.net/
COMMENT=	Fast and lightweight yet customizable window manager

USE_PKGINSTALL=	YES
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--enable-i18n

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.golem
PKG_SUPPORTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-sound
PLIST_SUBST=		NOT_SOUND=
.include "../../audio/esound/buildlink3.mk"
.else
PLIST_SUBST=		NOT_SOUND="@comment "
.endif

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/golem
CONF_FILES=	${EGDIR}/golemrc.default ${PKG_SYSCONFDIR}/golemrc

post-patch:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/sample.golem/golemrc > \
		${WRKSRC}/golemrc
	${RM} -f ${WRKSRC}/sample.golem/golemrc*

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/golemrc ${EGDIR}/golemrc.default

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
