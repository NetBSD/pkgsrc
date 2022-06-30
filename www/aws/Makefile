# $NetBSD: Makefile,v 1.40 2022/06/30 11:18:57 nia Exp $

DISTNAME=	aws-${AWS_VERSION}
PKGREVISION=	21
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libre.adacore.com/libre/tools/aws/
COMMENT=	Adacore Ada Web Server and framework
LICENSE=	gnu-gpl-v2

BROKEN=		"sh: ../xoscons: not found"

AWS_VERSION=		3.1.0.0
USE_TOOLS+=		gmake makeinfo sed awk
USE_LANGUAGES=		c ada c++ fortran

# Note: c++ and fortran aren't used, but gprconfig probes for them.
# When that happens, pkgsrc wrapper emits a warning message which causes
# gprconfig to crash due to output text not matching expected regexp
# Adding c++ and fortran to USE_LANGUAGES avoids this issue.

.include "options.mk"

MY_MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
MY_MAKE_ENV+=		AWK=awk
MY_MAKE_ENV+=		PATH=${PREFIX}/gcc5-aux/bin:${PATH:Q}
MY_CONF_ENV+=		PATH=${PREFIX}/gcc5-aux/bin:${PATH:Q}
CONFIGURE_ARGS+=	LPATH=${BUILDLINK_PREFIX.openssl}/lib
CONFIGURE_ARGS+=	ZPATH=${BUILDLINK_PREFIX.zlib}/lib

# Link options were added for the aws library
# "-R" option disables all rpaths except adalib and compiler libs.  This is
#      done because by default the rpaths will points at the WRKOBJDIR because
#      it doesn't support the concept of DESTDIR.
# "-Wl,-R" adds a second rpath string.
# -Wl,-rpath is a better choice, but synonym -Wl,-R works on all BSD and SunOS
SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adjust rpaths of shared libraries
SUBST_FILES.rpath=	src/src.gpr include/include.gpr
SUBST_FILES.rpath+=	demos/test_ldap/test_ldap.gpr tools/tools.gpr
SUBST_VARS.rpath=	ADDITIONAL_RPATH PREFIX
SUBST_SED.rpath+=	-e s,@RFLAG@,${LINKER_RPATH_FLAG},g
SUBST_SED.rpath+=	-e "s,@SSL_RPATH@,${BUILDLINK_PREFIX.openssl}/lib,g"
ADDITIONAL_RPATH=	${PREFIX}/lib:${PREFIX}/lib/aws/relocatable

GENERATE_PLIST=		cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+=	${FIND} * -type f | ${SORT};

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MY_CONF_ENV} \
		${GMAKE} setup ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MY_MAKE_ENV} \
		${GMAKE} build build_doc

do-test: install
	cd ${WRKSRC}/regtests && ${SETENV} ${MY_MAKE_ENV} \
		python${PYVERSSUFFIX} testsuite.py

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${GMAKE} install

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/gnatpython/buildlink3.mk"
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
