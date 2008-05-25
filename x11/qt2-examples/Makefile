# $NetBSD: Makefile,v 1.19 2008/05/25 21:42:22 joerg Exp $
#

PKGNAME=	qt2-examples-${QTVERSION}
PKGREVISION=	6
COMMENT=	QT2 Tutorial, example code and HTML documentation


.include "../../x11/qt2-libs/Makefile.common"

CONFIGURE_ENV+=	QTDIR=${QTPREFIX:Q}
NO_BUILD=	yes

SUBST_CLASSES+=		ex
SUBST_STAGE.ex=		do-build
SUBST_FILES.ex=		examples/*/Makefile tutorial/*/Makefile
SUBST_SED.ex=		-e 's:\$$[({]X11BASE[})]:${X11BASE}:g'
SUBST_SED.ex+=		-e 's:\$$[({]QTDIR[})]:${QTPREFIX}:g'
SUBST_SED.ex+=		-e 's:\$$[({]LOCALBASE[})]:${LOCALBASE}:g'
SUBST_SED.ex+=		-e 's:\$$[({]LIBTOOL[})]:${LIBTOOL}:g'

USE_TOOLS+=	pax

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*Makefile\.in$$,,' examples tutorial ${QTPREFIX}

.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
