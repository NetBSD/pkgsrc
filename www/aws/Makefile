# $NetBSD: Makefile,v 1.1.1.1 2011/02/11 16:48:52 drochner Exp $
#

DISTNAME=	aws-${AWS_VERSION}
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/aws/
COMMENT=	Adacore Ada Web Server and framework
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
AWS_VERSION=		2.10.0.1
USE_TOOLS+=		gmake makeinfo sed
BUILD_DEPENDS+=		gawk:../../lang/gawk

.include "options.mk"

MAKE_ENV+=	ADA_PROJECT_PATH=${PREFIX}/lib/gnat

post-wrapper:
	# We disable at least the wrapper binaries on all GNAT AUX to
	# avoid potential linkage problems
	${RM} ${WRKDIR}/.wrapper/bin/*

pre-configure:
	gprconfig --batch --config=Ada --config=C --config="Project File"

do-configure:
	cd ${WRKSRC} && ${SETENV} CC=gnatgcc \
	${GMAKE} setup ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} build build_doc

do-test: install
	cd ${WRKSRC}/regtests && python2.6 testsuite.py

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${GMAKE} install
	${TOUCH} ${DESTDIR}${PREFIX}/share/examples/aws/bin/IGNORE.ME
.if !empty (BUILD_DEMOS)
	${MAKE} demos
	${MAKE} demos-install
.endif

demos:
.for dd in ${DEMO_DIRS}
	cd ${WRKSRC}/demos/${dd} && ${GMAKE}
.endfor

demos-install:
.if !empty (BUILD_DEMOS)
	${MKDIR} ${DESTDIR}${PREFIX}/share/examples/aws/demos
.for dd in ${DEMO_DIRS}
	${FIND} ${WRKSRC}/demos/${dd} -type f -perm -0001 \
	-exec ${INSTALL} {} ${DESTDIR}${PREFIX}/share/examples/aws/demos/ \;
.endfor
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gnatpython/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
