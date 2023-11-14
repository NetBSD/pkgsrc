# $NetBSD: Makefile,v 1.11 2023/11/14 14:03:13 wiz Exp $
#

DISTNAME=	i3lock-2.8
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	https://i3wm.org/i3lock/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/i3lock/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	EGDIR=${EGDIR}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t

MESSAGE_SUBST+=	EGDIR=${EGDIR}

BUILD_DEFS+=	SYSCONFBASE

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		pam
SUBST_STAGE.pam=	pre-configure
SUBST_FILES.pam+=	i3lock.pam
SUBST_SED.pam+=		-e "s,login,system,g"
.elif ${OPSYS} == "Linux"
SUBST_CLASSES+=		pam
SUBST_STAGE.pam=	pre-configure
SUBST_FILES.pam+=	i3lock.pam
SUBST_SED.pam+=		-e "s,login,system-auth,g"
.endif

.if ${UNPRIVILEGED:tl} != "yes"
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/pam.d/i3lock \
			${SYSCONFBASE}/pam.d/i3lock
SPECIAL_PERMS+=		bin/i3lock ${SETUID_ROOT_PERMS}
.endif

.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
