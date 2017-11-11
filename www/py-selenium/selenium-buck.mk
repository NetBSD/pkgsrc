# $NetBSD: selenium-buck.mk,v 1.1 2017/11/11 21:30:21 tnn Exp $
#
#
# This Makefile fragment handles building selenium-buck; a build dependency
# of Selenium.

PREPEND_PATH+=	${WRKDIR}/buck-buck-release-${BUCK_VERSION}/bin

# buck needs python 2, even when we're targeting python 3.
BUILD_DEPENDS+=	python27-[0-9]*:../../lang/python27
BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

USE_TOOLS+=	bash gmake perl pkg-config
EXTRACT_USING=	bsdtar

DISTFILES?=	${DEFAULT_DISTFILES}

# Location of Selenium's buck fork.
BUCK_VERSION=		be2bf932342e5d67f58c9b26f5065c745d285d0d
BUCK_DIST=		buck-release-${BUCK_VERSION}.tar.gz
SITES.${BUCK_DIST}=	https://github.com/SeleniumHQ/buck/archive/
DISTFILES+=		${BUCK_DIST}

# We need to build libsqlitejdbc.so and libjnidispatch.so for the host
# platform and install them in buck's third party directory.
# They rely on prebuilt Linux binaries.

SQLITE_JDBC_VERSION=		3.20.0
SQLITE_JDBC_DIST=		sqlite-jdbc-${SQLITE_JDBC_VERSION}.tar.gz
SITES.${SQLITE_JDBC_DIST}=	-https://github.com/xerial/sqlite-jdbc/archive/${SQLITE_JDBC_VERSION}.tar.gz
DISTFILES+=			${SQLITE_JDBC_DIST}

SQLITE_AMALGAMATION_DIST=		sqlite-amalgamation-3200000.zip
SITES.${SQLITE_AMALGAMATION_DIST}=	https://www.sqlite.org/2017/
DISTFILES+=				${SQLITE_AMALGAMATION_DIST}

JNA_VERSION=			4.4.0
JNA_DIST=			jna-${JNA_VERSION}.tar.gz
SITES.${JNA_DIST}=		-https://github.com/java-native-access/jna/archive/${JNA_VERSION}.tar.gz
DISTFILES+=			${JNA_DIST}

${WRKDIR}/sqlite-jdbc_done:
	${MKDIR} ${WRKDIR}/sqlite-jdbc-${SQLITE_JDBC_VERSION}/target
	cp ${DISTDIR}/${SQLITE_AMALGAMATION_DIST} ${WRKDIR}/sqlite-jdbc-${SQLITE_JDBC_VERSION}/target/sqlite-${SQLITE_JDBC_VERSION}-amal.zip
	cd  ${WRKDIR}/sqlite-jdbc-${SQLITE_JDBC_VERSION} &&	\
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} jni-header native
	cd ${WRKDIR}/sqlite-jdbc-${SQLITE_JDBC_VERSION}/target/classes && \
	  ${PKG_JAVA_HOME}/bin/jar uvf ../../../buck-buck-release-${BUCK_VERSION}/third-party/java/sqlite/sqlite-jdbc-${SQLITE_JDBC_VERSION}.jar org/sqlite/native/${OPSYS}/${MACHINE_ARCH}/libsqlitejdbc.so
	touch $@

${WRKDIR}/jna_done:
	cd ${WRKDIR}/jna-${JNA_VERSION} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/ant -DX11BASE=${X11BASE} native
	cd ${WRKDIR}/jna-${JNA_VERSION}/build/classes &&	\
	  ${PKG_JAVA_HOME}/bin/jar uvf ../../../buck-buck-release-${BUCK_VERSION}/third-party/java/jna/jna-${JNA_VERSION}.jar com/sun/jna/${OPSYS:tl}-${MACHINE_ARCH:S/_/-/}/libjnidispatch.so
	touch $@

# After that is done, we can build buck itself using ant.
${WRKDIR}/buck_done: ${WRKDIR}/sqlite-jdbc_done ${WRKDIR}/jna_done
	cd ${WRKDIR}/buck-buck-release-${BUCK_VERSION} && ${SETENV} ${MAKE_ENV} ANT_OPTS=-Xmx1024M ${PREFIX}/bin/ant
	touch $@

pre-build: ${WRKDIR}/buck_done

# jna needs libffi and libXt headers
BUILDLINK_DEPMETHOD.libffi?=	build
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
