# $NetBSD: Makefile,v 1.14 2000/11/19 19:40:17 rh Exp $

DISTNAME=	gdm-2.0beta4
PKGNAME=	gdm-2.0b4
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gdm/} \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.README Daemon.png

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LIBS=		-lintl
LOCALSTATEDIR=	/var/gnome

EVAL_PREFIX+=	KDEBASEDIR=kdebase
CONFIGURE_ARGS+= --localstatedir=${LOCALSTATEDIR}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LIBS="${LIBS}" \
		LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL
MAKE_ENV+=	GDMOWN=${GDMOWN} GDMGRP=${GDMGRP}
PLIST_SUBST+=	GDMOWN=${GDMOWN} GDMGRP=${GDMGRP} \
		INSTALL="${INSTALL}" LOCALSTATEDIR="${LOCALSTATEDIR}"

GDMOWN=		daemon
GDMGRP=		daemon
GDMCFGDIR=	${PREFIX}/etc/gdm
GDMCFGFILES=	Default:Init.default/Default \
		PostSession:PostSession.default/Default \
		PreSession:PreSession.default/Default \
		Gnome:Sessions.default/Gnome \
		KDE:Sessions.default/KDE \
		Xsession:Sessions.default/Xsession \
		gdm.conf:gdm.conf.default \
		locale.alias:locale.alias.default \
		gnomerc:../gnomerc.default

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_PAM)
DEPENDS+=	PAM-*:../../security/PAM

post-patch:
	cd ${WRKSRC} &&					\
	${CP} configure configure.old &&		\
	${SED} -e 's:security/pam_appl.h::g'		\
		< configure.old > configure
.endif

post-build:
	for f in DEINSTALL INSTALL; do					\
		${SED} -e 's#@@CP@@#${CP}#'				\
		  -e 's#@@LN@@#${LN}#'					\
		  -e 's#@@MKDIR@@#${MKDIR}#'				\
		  -e 's#@@RM@@#${RM}#'					\
		  -e 's#@@GDMCFGDIR@@#${GDMCFGDIR}#g'			\
		  -e 's#@@GDMCFGFILES@@#${GDMCFGFILES:C/.*://g}#g'	\
		  ${PKGDIR}/$$f >${WRKDIR}/$$f;				\
	done
	cd ${WRKSRC}/config;						\
	for f in Default PostSession PreSession; do			\
		${SED} -e 's#/usr/bin/X11#${X11PREFIX}/bin#g' $$f >$$f.new; \
		${MV} $$f.new $$f;					\
		${CHMOD} +x $$f;					\
	done
	cd ${WRKSRC}/config;						\
	${RM} -f KDE Xsession;						\
	${ECHO} '#! ${SH}' >KDE;					\
	${ECHO} "export KDEDIR=${KDEBASEDIR}" >>KDE;			\
	${ECHO} 'exec $${KDEDIR}/bin/startkde $$@' >>KDE;		\
	${ECHO} '#! ${SH}' >Xsession;					\
	${ECHO} 'exec ${X11BASE}/lib/X11/xdm/Xsession $$@' >>Xsession;	\
	${CHMOD} +x KDE Xsession

post-install:
	${CHMOD} +x ${WRKSRC}/config/gnomerc
.for FILE in ${GDMCFGFILES}
	@cd ${WRKSRC}/config; \
	SOURCE=${FILE:C/:.*//}; \
	TARGET=${GDMCFGDIR}/${FILE:C/.*://:S/.default//}; \
	if [ ! -f $$TARGET ]; then \
	  ${ECHO} "installing $$SOURCE as $$TARGET"; \
	  if [ -x $$SOURCE ]; then \
	    ${INSTALL_SCRIPT} $$SOURCE $$TARGET; \
	  else \
	    ${INSTALL_DATA} $$SOURCE $$TARGET; \
	  fi; \
	fi; \
	TARGET=${GDMCFGDIR}/${FILE:C/.*://}; \
	${MKDIR} `dirname $$TARGET`; \
	${ECHO} "installing $$SOURCE as $$TARGET"; \
	if [ -x $$SOURCE ]; then \
	  ${INSTALL_SCRIPT} $$SOURCE $$TARGET; \
	else \
	  ${INSTALL_DATA} $$SOURCE $$TARGET; \
	fi
.endfor
	${MKDIR} ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.README ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/pixmaps
	${LN} -fs Gnome ${GDMCFGDIR}/Sessions/Default

.include "../../mk/bsd.pkg.mk"
