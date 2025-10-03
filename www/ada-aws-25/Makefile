# $NetBSD: Makefile,v 1.2 2025/10/03 11:54:06 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.1.0
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	aws
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/aws
COMMENT=	Ada Web Server
LICENSE=	gnu-gpl-v3

#GITHUB_SUBMODULES+=	AdaCore	templates-parser	v25.0.0	templates_parser

USE_LANGUAGES=	c ada

USE_TOOLS+=	gmake

HAS_CONFIGURE=	yes

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

LIBRARY_PATH?=		# empty

.include "options.mk"

#SUBST_CLASSES+=		version1
#SUBST_MESSAGE.version1=	Fix version number in ${SUBST_FILES.version1}
#SUBST_STAGE.version1=	post-extract
#SUBST_FILES.version1=	templates_parser/Makefile
#SUBST_SED.version1=	-e "s,22.0,25.1,"

SUBST_CLASSES+=		version2
SUBST_MESSAGE.version2=	Fix version number in ${SUBST_FILES.version2}
SUBST_STAGE.version2=	post-extract
SUBST_FILES.version2=	src/core/aws.ads
SUBST_SED.version2=	-e "s,20.0,25.1,"

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Replacing python interpreter in ${SUBST_FILES.python}
SUBST_STAGE.python=	post-extract
SUBST_FILES.python=	tools/awsascb
SUBST_SED.python=	-e "s,/usr/bin/env python,${PYTHONBIN},"

SUBST_CLASSES+=		sslcerts
SUBST_MESSAGE.sslcerts=	Replace SSL certs path in ${SUBST_FILES.sslcerts}
SUBST_STAGE.sslcerts=	post-extract
SUBST_FILES.sslcerts=	src/core/aws-default.ads
SUBST_SED.sslcerts=	-e "s,/etc/ssl/certs,${SSLCERTS},"

CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_ENV+=		INSTALL= LIBRARY_PATH=${PREFIX}/lib:${LIBRARY_PATH:Q}
CONFIGURE_ARGS+=	prefix=${GNAT_PREFIX}
CONFIGURE_ARGS+=	DEBUG=false
CONFIGURE_ARGS+=	GPRBUILD_OPTIONS=${GPRBUILD_OPTIONS:Q}
CONFIGURE_SCRIPT=	setup

PLIST_VARS+=		shlibs

USE_PKGSRC_GCC_RUNTIME?=			no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=					yes
CONFIGURE_ARGS+=				ENABLE_SHARED=true
BUILDLINK_DEPMETHOD.xmlada-25=			full
BUILDLINK_DEPMETHOD.libgpr-25=			full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=		full
BUILDLINK_DEPMETHOD.templates-parser-25=	full
# LAL dependencies
BUILDLINK_DEPMETHOD.gnatcoll-bindings-25=	full
BUILDLINK_DEPMETHOD.adasat-25=			full
BUILDLINK_DEPMETHOD.libgpr2-25=			full
BUILDLINK_DEPMETHOD.vss-25=			full
BUILDLINK_DEPMETHOD.prettier-ada-25=		full
BUILDLINK_DEPMETHOD.langkit-support-25=		full
BUILDLINK_DEPMETHOD.libadalang-25=		full
.else
CONFIGURE_ARGS+=				ENABLE_SHARED=false
.endif

CHECK_BUILTIN.zlib:= yes
.include "../../devel/zlib/builtin.mk"
CHECK_BUILTIN.zlib:= no
.if ${USE_BUILTIN.zlib:tl} == yes
MAKE_ENV+=	ZLIB_PATH=/usr/lib
.else
.include "../../devel/zlib/buildlink3.mk"
MAKE_ENV+=	ZLIB_PATH=${PREFIX}/lib
.endif

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/*
CHECK_RELRO_SKIP+=	${GNAT_PKGBASE}/lib/*.so

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.${SHLIB_EXT}.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-templates-parser-25/inplace.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
