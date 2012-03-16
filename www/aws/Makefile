# $NetBSD: Makefile,v 1.5 2012/03/16 04:31:15 obache Exp $
#

DISTNAME=	aws-${AWS_VERSION}
PKGREVISION=	2
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
USE_TOOLS+=		gmake makeinfo sed gawk

PYTHON_VERSIONS_ACCEPTED=	26 27

.include "options.mk"

MAKE_ENV+=	ADA_PROJECT_PATH=${PREFIX}/lib/gnat

GENERATE_PLIST=  cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+= ${FIND} bin/aws_password;
GENERATE_PLIST+= ${FIND} bin/awsres;
GENERATE_PLIST+= ${FIND} bin/templates2ada;
GENERATE_PLIST+= ${FIND} bin/templatespp;
GENERATE_PLIST+= ${FIND} bin/webxref;
GENERATE_PLIST+= ${FIND} bin/wsdl2aws;
GENERATE_PLIST+= ${FIND} include/aws/        -name \* -type f | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} lib/aws/            -name \* -type f | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} lib/gnat/aws/       -name \* -type f | ${SORT};
GENERATE_PLIST+= ${FIND} lib/gnat/aws.gpr;
GENERATE_PLIST+= ${FIND} share/doc/aws/      -name \* -type f | ${SORT};
GENERATE_PLIST+= ${FIND} share/examples/aws/ -name \* -type f | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} share/gps/plug-ins/ada2wsdl.xml;
GENERATE_PLIST+= ${FIND} share/gps/plug-ins/aws.py;
GENERATE_PLIST+= ${FIND} share/gps/plug-ins/aws.xml;
GENERATE_PLIST+= ${FIND} share/gps/plug-ins/aws_api.xml;
GENERATE_PLIST+= ${FIND} share/gps/plug-ins/wsdl2aws.xml;

post-wrapper:
	# We disable at least the wrapper binaries on all GNAT AUX to
	# avoid potential linkage problems
	${RM} ${WRKDIR}/.wrapper/bin/*

do-configure:
	cd ${WRKSRC} && ${SETENV} CC=gnatgcc \
	${GMAKE} setup ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} build build_doc

do-test: install
	cd ${WRKSRC}/regtests && python${PYVERSSUFFIX} testsuite.py

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${GMAKE} install
	${TOUCH} ${DESTDIR}${PREFIX}/share/examples/aws/bin/IGNORE.ME

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/gnatpython/buildlink3.mk"
.include "../../lang/gnat-aux/buildlink3.mk"
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
