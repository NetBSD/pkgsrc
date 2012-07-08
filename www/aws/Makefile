# $NetBSD: Makefile,v 1.6 2012/07/08 20:14:28 marino Exp $
#

DISTNAME=	aws-${AWS_VERSION}
PKGREVISION=	3
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
USE_LANGUAGES=  	c ada c++ fortran

# Note: c++ and fortran aren't used, but gprconfig probes for them.
# When that happens, pkgsrc wrapper emits a warning message which causes
# gprconfig to crash due to output text not matching expected regexp
# Adding c++ and fortran to USE_LANGUAGES avoids this issue.

PYTHON_VERSIONS_ACCEPTED=	26 27

.include "options.mk"

MAKE_ENV+=	ADA_PROJECT_PATH=${PREFIX}/lib/gnat

# Link options were added for the aws library
# "-R" option disables all rpaths except adalib and compiler libs.  This is
#      done because by default the rpaths will points at the WRKOBJDIR because
#      it doesn't support the concept of DESTDIR.
# "-Wl,-R" adds a second rpath string.
# -Wl,-rpath is a better choice, but synonym -Wl,-R works on all BSD and SunOS
SUBST_CLASSES+= 	rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adjust rpaths of shared libraries
SUBST_FILES.rpath=	src/src.gpr include/include.gpr
SUBST_SED.rpath=	-e "s,@ADDITIONAL_RPATH@,${ADDITIONAL_RPATH},"
ADDITIONAL_RPATH=	${PREFIX}/lib:${PREFIX}/lib/aws/native/relocatable

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

do-configure:
	cd ${WRKSRC} && ${GMAKE} setup ${CONFIGURE_ARGS}

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
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
