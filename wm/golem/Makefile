# $NetBSD: Makefile,v 1.32 2014/06/24 06:28:02 dholland Exp $
#

DISTNAME=	golem-0.0.5
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://golem.sourceforge.net/
COMMENT=	Fast and lightweight yet customizable window manager

USE_TOOLS+=	gmake yacc lex
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-i18n

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native" || exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.include "../../x11/libXinerama/buildlink3.mk"
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.golem
PKG_SUPPORTED_OPTIONS=	esound

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		esound
.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-sound
PLIST.esound=		yes
.include "../../audio/esound/buildlink3.mk"
.endif

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/golem
CONF_FILES=	${EGDIR}/golemrc.default ${PKG_SYSCONFDIR}/golemrc

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	sample.golem/golemrc
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS=	${EGDIR}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/golem/golemrc*
	${INSTALL_DATA} ${WRKSRC}/sample.golem/golemrc ${DESTDIR}${EGDIR}/golemrc.default

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
