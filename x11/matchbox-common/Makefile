# $NetBSD: Makefile,v 1.4 2006/03/04 21:31:10 jlam Exp $
#

DISTNAME=		matchbox-common-0.9.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://projects.o-hand.com/matchbox/sources/matchbox-common/0.9/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
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
