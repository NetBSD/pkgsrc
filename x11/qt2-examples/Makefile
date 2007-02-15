# $NetBSD: Makefile,v 1.17 2007/02/15 14:51:10 rillig Exp $
#

PKGNAME=	qt2-examples-${QTVERSION}
PKGREVISION=	6
COMMENT=	QT2 Tutorial, example code and HTML documentation


.include "../../x11/qt2-libs/Makefile.common"

CONFIGURE_ENV+=	QTDIR=${QTPREFIX:Q}

SUBST_CLASSES+=		ex
SUBST_STAGE.ex=		do-build
SUBST_FILES.ex=		examples/*/Makefile tutorial/*/Makefile
SUBST_SED.ex=		-e 's:\$$[({]X11BASE[})]:${X11BASE}:g'
SUBST_SED.ex+=		-e 's:\$$[({]QTDIR[})]:${QTPREFIX}:g'
SUBST_SED.ex+=		-e 's:\$$[({]LOCALBASE[})]:${LOCALBASE}:g'
SUBST_SED.ex+=		-e 's:\$$[({]LIBTOOL[})]:${LIBTOOL}:g'

do-install:
	cd ${WRKSRC} && pax -wr examples tutorial ${QTPREFIX}

.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
