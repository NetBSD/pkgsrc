# $NetBSD: Makefile,v 1.25 2001/09/30 07:39:48 tron Exp $

DISTNAME=	gdm-2.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gdm/} \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.README Daemon.png

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

DEPENDS+=	gnome-libs-[0-9]*:../../x11/gnome-libs
DEPENDS+=	libglade>=0.16:../../devel/libglade

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBINTL=    YES

CPPFLAGS=	-I${LOCALBASE}/include
LIBS=		-lintl
LOCALSTATEDIR=	/var/gnome

EVAL_PREFIX+=	KDEBASEDIR=kdebase
CONFIGURE_ARGS+= --localstatedir=${LOCALSTATEDIR}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
		GDMOWN=${GDMOWN} GDMGRP=${GDMGRP}

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

.if defined(USE_PAM)
DEPENDS+=	PAM-[0-9]*:../../security/PAM
.else

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
	${SED} "s|@PREFIX@|${PREFIX}|g" ${FILESDIR}/gdm > ${WRKDIR}/gdm

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
	${INSTALL_DATA_DIR} `dirname $$TARGET`; \
	${ECHO} "installing $$SOURCE as $$TARGET"; \
	if [ -x $$SOURCE ]; then \
	  ${INSTALL_SCRIPT} $$SOURCE $$TARGET; \
	else \
	  ${INSTALL_DATA} $$SOURCE $$TARGET; \
	fi
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.README ${PREFIX}/share/doc/gdm
	${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/pixmaps
	${LN} -fs Gnome ${GDMCFGDIR}/Sessions/Default
	${INSTALL_SCRIPT} ${WRKDIR}/gdm ${PREFIX}/etc/rc.d/

.include "../../mk/bsd.pkg.mk"
