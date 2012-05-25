# $NetBSD: Makefile,v 1.9 2012/05/25 21:00:26 reed Exp $
#

DISTNAME=	dmenu-4.5
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://tools.suckless.org/dmenu
COMMENT=	Dynamic menu for X
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

NO_CONFIGURE=	yes

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,/usr/X11R6,${X11BASE},'
# -D_XOPEN_SOURCE=600 is needed for usleep(3) and S_ISLNK() macro in <sys/stat.h>
SUBST_SED.makefile+=	-e 's,^CPPFLAGS *= ,CPPFLAGS = -D_XOPEN_SOURCE=600 ,'
SUBST_SED.makefile+=	-e 's,^CFLAGS *= ,CFLAGS += ,'
SUBST_SED.makefile+=	-e 's,^LDFLAGS *= ,LDFLAGS += ,'
SUBST_SED.makefile+=	-e 's/cc/${CC:Q}/'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
