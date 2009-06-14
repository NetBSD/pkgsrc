# $NetBSD: Makefile,v 1.4 2009/06/14 22:48:51 ahoka Exp $
#

DISTNAME=	dmenu-4.0
CATEGORIES=	x11
MASTER_SITES=	http://code.suckless.org/dl/tools/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://tools.suckless.org/dmenu
COMMENT=	Dymanic menu for X

LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
SUBST_SED.makefile+=	-e 's,^CFLAGS = ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS = ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
