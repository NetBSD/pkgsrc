# $NetBSD: Makefile,v 1.5 2003/09/29 09:54:28 seb Exp $

DISTNAME=	xalarm-3.03
PKGNAME=	xalarm-3.05
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xalarm
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=R5contrib-fixes/xalarm/}
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	${MASTER_SITE_XCONTRIB:=R5contrib-fixes/xalarm/}
PATCHFILES=	xalarm-3.03-04.patch.Z xalarm-3.04-05.patch.Z
PATCH_DIST_STRIP=-p1

MAINTAINER=	seb@NetBSD.org
COMMENT=	X11 interactive alarm clock

DEPENDS+=	skill>=4.0:../../sysutils/skill

USE_IMAKE=	yes

FORTUNE=	"Sorry, xfortune is unavailable - no fortune!"
YOW=		"Sorry, xyow is unavailable - no yow!"
KILL=		/bin/kill # should this be in bsd.pkg.mk ?

.include "../../mk/bsd.prefs.mk"

.if defined(XALARM_USE_YOW)
DEPENDS+=	emacs>=20.7:../../editors/emacs
.endif

.if ${OPSYS} == "NetBSD"
.if exists(/usr/games/fortune)
FORTUNE=	`/usr/games/fortune`
.endif
MAKE_FLAGS+=	EXTRA_DEFINES=-DFORKRETURNSPID_T
.endif

pre-configure:
.if defined(XALARM_USE_YOW)
	# if multiple version emacs of emacs are there, take the higher one...
	YOW=`${FIND} ${LOCALBASE}/libexec/emacs -name yow -print 2>/dev/null | ${SORT} -rn | ${HEAD} -1` ;  \
	if ${TEST} x$${YOW} = x ; then \
		YOW=${YOW} ; \
	fi ; ${SETENV} YOW=$${YOW} \
	${SED}  -e "s|@PRG@|\`$${YOW}\`|" \
		-e 's|@XPRG@|xyow|' \
		${FILESDIR}/xprg > ${WRKSRC}/xyow
.else
	${SED}  -e 's|@PRG@|${YOW}|' \
		-e 's|@XPRG@|xyow|' \
		${FILESDIR}/xprg > ${WRKSRC}/xyow
.endif
	${SED}  -e 's|@PRG@|${FORTUNE}|' \
		-e 's|@XPRG@|xfortune|' \
		${FILESDIR}/xprg > ${WRKSRC}/xfortune
	${SED}  -e 's|@SKILL@|${LOCALBASE}/bin/skill|' \
		-e 's|@GREP@|${GREP}|' \
		-e 's|@KILL@|${KILL}|' ${FILESDIR}/fns.h.in > ${WRKSRC}/fns.h

.include "../../mk/bsd.pkg.mk"
