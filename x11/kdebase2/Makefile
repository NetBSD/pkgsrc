# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 16:03:09 skrll Exp $

DISTNAME=	kdebase-2.1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Base modules for the KDE 2 integrated X11 desktop

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Daemon.png Daemon.README

BUILD_DEPENDS+=	${QT2DIR}/qt2/bin/uic:../../x11/qt2-designer
BUILD_DEPENDS+=	${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	kdelibs-2.1:../../x11/kdelibs2

# kdebase doesn't manipulate GIFs, but KDE packages depending on kdebase
# often do, so put the dependency here.
#
DEPENDS+=	libungif-*:../../graphics/libungif

USE_XPM=	yes
USE_MOTIF=	yes
.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=	LIBS="-Wl,--export-dynamic"

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
IMAKEDIR=	${WRKDIR}/imake

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "a.out"
BORKEN=		"This package doesn't build on a.out. This is being worked on."
.endif

post-configure:
	${MKDIR} ${IMAKEDIR}
	${LN} -fs ${FILESDIR}/Imakefile ${IMAKEDIR}
	cd ${IMAKEDIR} && \
	${XMKMF} && ${MAKE} hasxdmauth >>${WRKSRC}/kdm/kdm-config.h
	${RM} -rf ${IMAKEDIR}

post-install:
	@${CHMOD} u+s ${PREFIX}/bin/konsole_grantpty
	@${CHMOD} u+s ${PREFIX}/bin/*.kss
	@# NetBSD Advertisement O:-)
	@cd ${PREFIX}/share/kde/config ; \
	${CP} kdmrc kdmrc.new ; \
	${SED} \
		-e 's|^\(GreetString\)=.*|\1=Welcome to ${OPSYS}! [HOSTNAME]|' \
		<kdmrc.new >kdmrc ; \
	${ECHO} 'LogoPixmap=${PREFIX}/share/kde/icons/Daemon.png' >>kdmrc ; \
	${RM} kdmrc.new
	@${INSTALL_DATA} ${DISTDIR}/Daemon.png ${PREFIX}/share/kde/icons
	@${INSTALL_DATA} ${DISTDIR}/Daemon.README \
	  ${PREFIX}/share/doc/kde/HTML/en/kdm

.include "../../mk/bsd.pkg.mk"
