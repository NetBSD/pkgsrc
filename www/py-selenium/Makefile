# $NetBSD: Makefile,v 1.1 2017/11/11 21:30:21 tnn Exp $

DISTNAME=	selenium-3.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	selenium
GITHUB_TAG=	${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=SeleniumHQ/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://github.com/SeleniumHQ/selenium/
COMMENT=	Browser automation framework (python bindings)
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools>=36:../../devel/py-setuptools

USE_LANGUAGES=	c c++
USE_JAVA=	build

EGG_NAME=	selenium-3.7.0
PYSETUPSUBDIR=	py
WRKSRC=		${WRKDIR}/selenium-${DISTNAME}

.include "../../mk/bsd.prefs.mk"

# We need a native JDK for selenium-buck.
PKG_JVMS_ACCEPTED=	openjdk8
.if ${OPSYS} == "Linux"
# Oracle JDK should be feasible on Linux.
PKG_JVMS_ACCEPTED+=	oracle-jdk8
.endif

.include "../../mk/java-vm.mk"

# Every new platform will need patches due to the crazy build framework.
ONLY_FOR_PLATFORM=	Linux-*-x86_64 NetBSD-*-x86_64

pre-build:
# This tells Selenium that we will provide external buck in $PATH.
	${TOUCH} ${WRKSRC}/.nobuckcheck
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./go --trace py_prep_for_install_release

.include "selenium-buck.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
