# $NetBSD: Makefile,v 1.43 2023/06/27 10:41:06 riastradh Exp $

DISTNAME=		xorg-cf-files-1.0.8
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg imake rules

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

DARWIN_USE_QUARTZ?=	1

# SmartOS puts compiler tools in /usr/bin and does not come with lex/yacc.
.if ${OS_VARIANT} == "SmartOS"
DEPENDS+=		byacc-[0-9]*:../../devel/byacc
DEPENDS+=		flex-[0-9]*:../../devel/flex
SUBST_CLASSES+=		fixpaths
SUBST_STAGE.fixpaths=	pre-configure
SUBST_MESSAGE.fixpaths=	Fixing compiler tool paths
SUBST_FILES.fixpaths=	svr4.cf
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/ar,/usr/bin/ar,g'
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/ld,/usr/bin/ld,g'
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/lex,${PREFIX}/bin/flex,g'
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/yacc,${PREFIX}/bin/yacc,g'
.endif

.include "../../mk/bsd.prefs.mk"

post-extract:
	${CP} ${FILESDIR}/host.def ${WRKSRC}
	${CP} ${FILESDIR}/xorgsite.def ${WRKSRC}

pre-configure:
.for sys in NetBSD FreeBSD DragonFly linux darwin sun
	mv ${WRKSRC}/${sys}.cf ${WRKSRC}/${sys}.cf.before && \
	${SED} -e "s|@@PKGSRC_CC@@|${CC}|g"		\
		-e "s|@@PKGSRC_CPP@@|${CPP}|g"		\
		-e "s|@@PKGSRC_CXX@@|${CXX}|g"		\
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g"	\
		-e "s|@@DARWIN_USE_QUARTZ@@|${DARWIN_USE_QUARTZ}|g"	\
		-e "s|@@INSTALL@@|${INSTALL}|g"	\
		${WRKSRC}/${sys}.cf.before > ${WRKSRC}/${sys}.cf
.endfor
.if ${USE_CROSS_COMPILE:tl} != "yes" # MAKE_PROGRAM is wrong; empty host.def is fine
	${SED} -e "s|@PREFIX@|${PREFIX}|g"		\
		-e "s|@PKGMANDIR@|${PKGMANDIR}|"	\
		-e "s|@MAKE@|${MAKE_PROGRAM}|"	${FILESDIR}/host.def > \
		${WRKSRC}/host.def
	if [ ${X11BASE} != ${PREFIX} ]; then \
		${ECHO} '#define RealProjectRoot ${X11BASE}' >> ${WRKSRC}/host.def; \
	fi
.endif

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
