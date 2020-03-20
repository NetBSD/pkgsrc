# $NetBSD: Makefile,v 1.37 2020/03/20 11:58:33 nia Exp $
#

DISTNAME=	golem-0.0.5
PKGREVISION=	7
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://golem.sourceforge.net/
COMMENT=	Fast and lightweight yet customizable window manager

USE_TOOLS+=	gmake yacc lex
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-i18n
CONFIGURE_ARGS+=	--disable-sound

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native" || exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.include "../../x11/libXinerama/buildlink3.mk"
.endif

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/golem
CONF_FILES=	${EGDIR}/golemrc.default ${PKG_SYSCONFDIR}/golemrc

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	sample.golem/golemrc
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

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
