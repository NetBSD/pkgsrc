# $NetBSD: Makefile,v 1.5 2026/02/06 10:06:17 wiz Exp $

DISTNAME=	kscreenlocker-${PLASMAVER}
PKGREVISION=	4
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Library and components for secure lock screen architecture
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	pam-pwauth_suid>=1.2:../../security/pam-pwauth_suid

USE_TOOLS+=	msgmerge pkg-config

EGDIR=		share/examples/pam.d

CONF_FILES+=	${EGDIR}/kde ${PKG_SYSCONFBASEDIR}/pam.d/kde

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	sed s:%%PREFIX%%:${PREFIX}: < ${FILESDIR}/kde.pam.in > ${DESTDIR}${PREFIX}/${EGDIR}/kde

.include "../../mk/pam.buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../graphics/kf6-ksvg/buildlink3.mk"
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../x11/plasma6-libkscreen/buildlink3.mk"
.include "../../x11/plasma6-libplasma/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
