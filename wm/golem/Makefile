# $NetBSD: Makefile,v 1.7 2004/02/14 00:54:46 grant Exp $
#

DISTNAME=	golem-0.0.5
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golem/}

MAINTAINER=	reide@darkest.org
HOMEPAGE=	http://golem.sourceforge.net/
COMMENT=	Fast and lightweight yet customizable window manager

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--enable-i18n

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

GOLEM_WITH_SOUND?=	NO

.if !empty(GOLEM_WITH_SOUND:M[Yy][Ee][Ss])
BUILD_DEFS=		GOLEM_WITH_SOUND
CONFIGURE_ARGS+=	--enable-sound
PLIST_SUBST=		NOT_SOUND=
.include "../../audio/esound/buildlink2.mk"
.else
PLIST_SUBST=		NOT_SOUND="@comment "
.endif

CFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

EGDIR=		${PREFIX}/share/examples/golem
CONF_FILES=	${EGDIR}/golemrc.default ${PKG_SYSCONFDIR}/golemrc

post-patch:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/sample.golem/golemrc > \
		${WRKSRC}/golemrc
	${RM} -f ${WRKSRC}/sample.golem/golemrc*

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/golemrc ${EGDIR}/golemrc.default

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
