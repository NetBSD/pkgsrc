# $NetBSD: Makefile,v 1.33 2002/11/28 11:01:32 tron Exp $

DISTNAME=	gdm-2.2.0
PKGREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdm/2.2/} \
		${MASTER_SITE_LOCAL}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.README Daemon.png

MAINTAINER=	mjl@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Display Manager - a re-implementation of the xdm program

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_X11BASE=	YES

LOCALSTATEDIR=	/var/gnome

EVAL_PREFIX+=	KDEBASEDIR=kdebase
CONFIGURE_ARGS+= --localstatedir=${LOCALSTATEDIR}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
		GDMOWN=${GDMOWN} GDMGRP=${GDMGRP}

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL
MAKE_ENV+=	GDMOWN=${GDMOWN} GDMGRP=${GDMGRP}
MAKE_ENV+=	CHMOD=${CHMOD} CHOWN=${CHOWN}
PLIST_SUBST+=	GDMOWN=${GDMOWN} GDMGRP=${GDMGRP} \
		INSTALL="${INSTALL}" LOCALSTATEDIR="${LOCALSTATEDIR}"

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

.if ${OPSYS} == "SunOS"
CFLAGS+= -DSunOS
GDMOWN=		daemon
GDMGRP=		other
.else
GDMOWN=		daemon
GDMGRP=		daemon
.endif

.if defined(USE_PAM)
DEPENDS+=	PAM-[0-9]*:../../security/PAM
.else

post-patch:
	cd ${WRKSRC} &&					\
	${CP} configure configure.old &&		\
	${SED} -e 's:security/pam_appl.h:nopam:g'	\
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
		${SED} -e 's#/usr/bin/X11#${X11BASE}/bin#g' $$f >$$f.new; \
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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
