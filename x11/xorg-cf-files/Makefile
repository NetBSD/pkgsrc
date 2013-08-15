# $NetBSD: Makefile,v 1.26 2013/08/15 08:15:04 jperkin Exp $

DISTNAME=		xorg-cf-files-1.0.5
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=util/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
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
SUBST_STAGE.fixpaths=	post-patch
SUBST_MESSAGE.fixpaths=	Fixing compiler tool paths
SUBST_FILES.fixpaths=	svr4.cf
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/ar,/usr/bin/ar,g'
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/ld,/usr/bin/ld,g'
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/lex,${PREFIX}/bin/flex,g'
SUBST_SED.fixpaths+=	-e 's,/usr/ccs/bin/yacc,${PREFIX}/bin/yacc,g'
.endif

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
	${SED} -e "s|@PREFIX@|${PREFIX}|g"		\
		-e "s|@PKGMANDIR@|${PKGMANDIR}|"	\
		-e "s|@MAKE@|${MAKE_PROGRAM}|"	${FILESDIR}/host.def > \
		${WRKSRC}/host.def
	if [ ${X11BASE} != ${PREFIX} ]; then \
		${ECHO} '#define RealProjectRoot ${X11BASE}' >> ${WRKSRC}/host.def; \
	fi

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
