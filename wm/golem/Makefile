# $NetBSD: Makefile,v 1.23 2006/12/15 20:33:02 joerg Exp $
#

DISTNAME=	golem-0.0.5
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://golem.sourceforge.net/
COMMENT=	Fast and lightweight yet customizable window manager

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-i18n

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.golem
PKG_SUPPORTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-sound
PLIST_SUBST+=		NOT_SOUND=
.include "../../audio/esound/buildlink3.mk"
.else
PLIST_SUBST+=		NOT_SOUND="@comment "
.endif

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/golem
CONF_FILES=	${EGDIR}/golemrc.default ${PKG_SYSCONFDIR}/golemrc

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	sample.golem/golemrc
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

post-install:
	${RM} -f ${PREFIX}/share/golem/golemrc*
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.golem/golemrc ${EGDIR}/golemrc.default

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
