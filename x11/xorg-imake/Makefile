# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 04:49:52 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-imake-${XORG_VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R6.7.0-src1.tar.gz X11R6.7.0-src3.tar.gz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	Imake and other utilities from X.org

PKG_INSTALLATION_TYPES= overwrite pkgviews

CONFLICTS+=	imake-[0-9]*

USE_BUILDLINK3=		yes
INSTALL_TARGET=		install install.man
NO_XORG_TARGETS=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
PLIST_SUBST+=	LNDIR=
.elif ${OPSYS} == "OpenBSD"
PLIST_SUBST+=	LNDIR="@comment "
.else
PLIST_SUBST+=	LNDIR=
.endif

.include "../../meta-pkgs/xorg/Makefile.common"

post-extract:
.for F in ${SYSTEMS}
	@${MV} ${WRKSRC}/config/cf/${F}.cf \
		${WRKSRC}/config/cf/${F}.cf.in
.endfor
.undef F

pre-configure:
.for F in ${SYSTEMS}
	@${SED} -e "s|@@PKGSRC_CC@@|${CC}|g" \
		-e "s|@@PKGSRC_CPP@@|${CPP}|g" \
		-e "s|@@PKGSRC_CXX@@|${CXX}|g" \
		-e "s|@@PKGSRC_CFLAGS@@|${CFLAGS}|g" \
		${WRKSRC}/config/cf/${F}.cf.in > \
		${WRKSRC}/config/cf/${F}.cf
.endfor
.undef F

do-build:
	@${TOUCH} ${WRKSRC}/config/cf/version.def
	@${TOUCH} ${WRKSRC}/config/cf/date.def
	@${CP} ${FILESDIR}/xorgsite.def ${WRKSRC}/config/cf
	@${SED} -e "s|@PREFIX@|${X11ROOT}|g"		\
		-e "s|@PREFIX@|${X11ROOT}|g"		\
		-e "s|@BLNK@|${BUILDLINK_DIR}|g"	\
		-e "s|@LOCALBASE@|${LOCALBASE}|g "	\
		-e "s|@MAKE@|${MAKE_PROGRAM}|"	${FILESDIR}/host.def > \
		${WRKSRC}/config/cf/host.def
	cd ${WRKSRC} && ${MAKE} Makefile.boot && \
	${MAKE_PROGRAM} -f xmakefile VerifyOS version.def Makefiles includes

.include "../../mk/bsd.pkg.mk"
