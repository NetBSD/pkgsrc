# $NetBSD: Makefile,v 1.4 2023/11/12 13:23:46 wiz Exp $

DISTNAME=	cde-2.5.1
PKGREVISION=	3
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdesktopenv/files/src/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://cdesktopenv.sourceforge.net/
COMMENT=	Common Desktop Environment
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf automake autoreconf
USE_TOOLS+=	awk:run bdftopcf gettext gmake gzip ksh
USE_TOOLS+=	lex mkfontdir patch perl pkg-config yacc

MAKE_JOBS_SAFE=		no

PTHREAD_AUTO_VARS=		yes
BUILDLINK_TRANSFORM+=		rm:-pthread
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/dt/lib

.include "../../mk/bsd.fast.prefs.mk"

DEPENDS+=	ksh93-[0-9]*:../../shells/ksh93
DEPENDS+=	font-adobe-75dpi-[0-9]*:../../fonts/font-adobe-75dpi
DEPENDS+=	font-adobe-100dpi-[0-9]*:../../fonts/font-adobe-100dpi
.if ${X11_TYPE} == "modular"
DEPENDS+=	xrdb-[0-9]*:../../x11/xrdb
DEPENDS+=	xset-[0-9]*:../../x11/xset
.endif
TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/dt
CONFIGURE_ENV+=		ac_cv_path_KSH=${PREFIX}/bin/ksh93
CONFIGURE_ENV+=		GZIP=${GZIP_CMD:Q}
CONFIGURE_ARGS+=	MAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/dt

.include "options.mk"

REPLACE_PERL+=	programs/dtinfo/tools/bin/ccdate
REPLACE_AWK+=	programs/dtlogin/config/Xsession.src

REPLACE_INTERPRETER+=	dtksh
REPLACE.dtksh.old=	.*/bin/dtksh
REPLACE.dtksh.new=	${PREFIX}/dt/bin/dtksh
REPLACE_FILES.dtksh+=	programs/dthelp/dthelpgen/dthelpgen.dtsh

REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*/bin/tclsh
REPLACE.tclsh.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tclsh+=	programs/dtdocbook/tcl/docbook.tcl

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_FILES.iconv+=	programs/dtmail/libDtMail/Common/Session.C
SUBST_FILES.iconv+=	programs/dtmail/libDtMail/RFC/RFCBodyPart.C
SUBST_SED.iconv=	-e 's!^[[:space:]]*const char .ip = (const char .) .bp!char *ip = *bp!'
SUBST_MESSAGE.iconv=	Fix for GNU iconv.
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	configure.ac
SUBST_FILES.paths+=	pkgsrc/startcde
SUBST_FILES.paths+=	pkgsrc/README.*
SUBST_FILES.paths+=	programs/dtlogin/Makefile.am
SUBST_VARS.paths=	PKG_SYSCONFDIR PREFIX REAL_ROOT_GROUP VARBASE X11BASE
SUBST_MESSAGE.paths=	Replacing path placeholders.

MAKE_ENV+=	x_includes=${X11BASE}/include
MAKE_FLAGS+=	YACC=${YACC:Q}
MAKE_FLAGS+=	PERL=${PERL5:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtterm ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtapppgather ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	${PREFIX}/dt/bin/dtmail ${REAL_ROOT_USER} mail 2755

RCD_SCRIPTS=	dtlogin

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
.for i in .alias .dir
CONF_FILES+=	${PREFIX}/dt/share/cde/fontaliases/fonts${i} \
		${PKG_SYSCONFDIR}/dt/config/xfonts/C/fonts${i}
.endfor

BUILD_DEFS+=		VARBASE
OWN_DIRS+=		${VARBASE}/dt
.for d in dt/appconfig/appmanager dt/tmp spool/calendar
OWN_DIRS+=		${VARBASE}/${d}
OWN_DIRS_PERMS+=	${VARBASE}/${d} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0770
.endfor
OWN_DIRS+=		${PKG_SYSCONFDIR}/dt/config
OWN_DIRS+=		${PKG_SYSCONFDIR}/dt/config/Xsession.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/dt/config/xfonts/C

INSTALLATION_DIRS+=	bin share/doc/${PKGBASE}

post-extract:
	${RUN}${MKDIR} ${WRKSRC}/pkgsrc
	${RUN}${CP} ${FILESDIR}/startcde.sh ${WRKSRC}/pkgsrc/startcde
.for f in README.*
	${RUN}${CP} ${FILESDIR}/${f} ${WRKSRC}/pkgsrc
.endfor

pre-configure:
	${RUN}${CHMOD} u+w ${WRKDIR}/*
	${RUN}for f in `${FIND} ${WRKSRC} -type f | ${XARGS} ${GREP} -l '/usr/bin/X11'`; do \
		${ECHO} Replacing X11 binary path in $$f ; \
		${SED} -e 's:/usr/bin/X11:${X11BASE}/bin:g' $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	${RUN}for f in `${FIND} ${WRKSRC} -type f | ${XARGS} ${GREP} -l '/usr/dt'`; do \
		${ECHO} Replacing CDE prefix in $$f ; \
		${SED} -e 's:/usr/dt:${PREFIX}/dt:g' $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	${RUN}for f in `${FIND} ${WRKSRC} -type f | ${XARGS} ${GREP} -l '/etc/dt'`; do \
		${ECHO} Replacing CDE syscondir in $$f ; \
		${SED} -e 's:/etc/dt:${PKG_SYSCONFDIR}/dt:g' $$f > $$f.pdone && ${MV} $$f.pdone $$f; \
	done
	${RUN}set -e; cd ${WRKSRC} && autoreconf -fiv

post-install:
	${RUN}${FIND} ${DESTDIR}${PREFIX}/dt -type f -perm -111 -exec	\
		${SH} -c '${STRIP} --strip-unneeded {} > /dev/null 2>&1' \;
	${INSTALL_SCRIPT} ${WRKSRC}/pkgsrc/startcde ${DESTDIR}${PREFIX}/bin
.for f in CONTRIBUTORS COPYING HISTORY README.md
	${RUN}${MV} ${DESTDIR}${PREFIX}/dt/${f}				\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor
.for r in README.*
	${INSTALL_DATA} ${WRKSRC}/pkgsrc/${r}				\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
