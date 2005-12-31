# $NetBSD: Makefile,v 1.1.1.1 2005/12/31 13:26:20 peter Exp $
#

DISTNAME=		matchbox-common-0.9.1
CATEGORIES=		x11
MASTER_SITES=		http://projects.o-hand.com/matchbox/sources/matchbox-common/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://projects.o-hand.com/matchbox/
COMMENT=		Shared icons and configuration data for Matchbox

GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	matchbox

SUBST_CLASSES+=		session
SUBST_MESSAGE.session=	"Fixing location of system-wide matchbox session."
SUBST_STAGE.session=	pre-configure
SUBST_FILES.session=	matchbox-session
SUBST_SED.session=	-e 's|/etc/matchbox|${PKG_SYSCONFDIR}|g'

.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
