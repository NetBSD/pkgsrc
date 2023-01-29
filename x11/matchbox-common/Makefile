# $NetBSD: Makefile,v 1.23 2023/01/29 21:18:16 ryoon Exp $
#

DISTNAME=		matchbox-common-0.9.1
PKGREVISION=		13
CATEGORIES=		x11
MASTER_SITES=		http://downloads.yoctoproject.org/releases/matchbox/matchbox-common/0.9/
MASTER_SITES+=		http://mirrors.kernel.org/yocto/matchbox/matchbox-common/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matchbox-project.org/
COMMENT=		Shared icons and configuration data for Matchbox

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKG_SYSCONFSUBDIR=	matchbox

SUBST_CLASSES+=		session
SUBST_MESSAGE.session=	Fixing location of system-wide matchbox session.
SUBST_STAGE.session=	pre-configure
SUBST_FILES.session=	matchbox-session
SUBST_SED.session=	-e 's|/etc/matchbox|${PKG_SYSCONFDIR}|g'

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
