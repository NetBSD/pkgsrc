# $NetBSD: Makefile,v 1.17 2013/04/06 13:01:28 rodent Exp $

DISTNAME=	xalarm-3.06
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	X11 interactive alarm clock

DEPENDS+=	skill>=4.0:../../sysutils/skill

USE_IMAKE=	yes
XAW_TYPE?=	3d

FORTUNE=	"Sorry, xfortune is unavailable - no fortune!"
YOW=		"Sorry, xyow is unavailable - no yow!"
KILL=		/bin/kill # should this be in bsd.pkg.mk ?

.include "../../mk/bsd.prefs.mk"

.if defined(XALARM_USE_YOW)
DEPENDS+=	emacs20>=20.7:../../editors/emacs
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
	${CP} ${FILESDIR}/XAlarm-color.ad ${WRKSRC}/

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
