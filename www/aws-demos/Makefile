# $NetBSD: Makefile,v 1.10 2014/01/01 11:52:37 wiz Exp $
#

DISTNAME=	aws-${AWS_VERSION}
PKGNAME=	aws-demos-${AWS_VERSION}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/aws/
COMMENT=	Adacore Ada Web Server demonstration programs
LICENSE=	gnu-gpl-v2

AWS_VERSION=		3.1.0.0
USE_TOOLS+=		gmake makeinfo sed awk
USE_LANGUAGES=		c ada c++ fortran
PATCHDIR=		${.CURDIR}/../../www/aws/patches
DISTINFO_FILE=		${.CURDIR}/../../www/aws/distinfo
CONFIGURE_ARGS+=	GCC=ada
CONFIGURE_ARGS+=	PROCESSORS=1
CONFIGURE_ARGS+=	PYTHON=python${PYVERSSUFFIX}
CONFIGURE_ARGS+=	XMLADA=true
CONFIGURE_ARGS+=	prefix=${PREFIX}
CONFIGURE_ARGS+=	DEBUG=true

MAKE_ENV+=		ADA_PROJECT_PATH=${PREFIX}/lib/gnat
MAKE_ENV+=		AWK=awk
CONFIGURE_ARGS+=	LPATH=${PREFIX}/lib ZPATH=/usr/lib

SUBST_CLASSES+= 	lpath
SUBST_STAGE.lpath=	post-patch
SUBST_MESSAGE.lpath=	Add library path for ldap
SUBST_FILES.lpath=	demos/test_ldap/test_ldap.gpr
SUBST_SED.lpath=	-e 's|@PREFIX@|${PREFIX}|g'

DEMO_DIRS+=	auth
DEMO_DIRS+=	autobahn
DEMO_DIRS+=	cert
DEMO_DIRS+=	com
DEMO_DIRS+=	dispatch
DEMO_DIRS+=	dowload_manager
DEMO_DIRS+=	hello_world
DEMO_DIRS+=	hotplug
DEMO_DIRS+=	jabber_demo
DEMO_DIRS+=	multiple_sessions
DEMO_DIRS+=	res_demo
DEMO_DIRS+=	soap_demo
DEMO_DIRS+=	soap_disp
DEMO_DIRS+=	soap_vs
DEMO_DIRS+=	split
DEMO_DIRS+=	test_mail
DEMO_DIRS+=	text_input
DEMO_DIRS+=	upload
DEMO_DIRS+=	vh_demo
DEMO_DIRS+=	web_block
DEMO_DIRS+=	web_block_ajax
DEMO_DIRS+=	web_block_ajax_templates
DEMO_DIRS+=	web_elements
DEMO_DIRS+=	web_mail
DEMO_DIRS+=	websockets
DEMO_DIRS+=	wps
DEMO_DIRS+=	ws
DEMO_DIRS+=	zdemo

# These don't build, fail finding "aws.ini"
#DEMO_DIRS+=	interoplab
#DEMO_DIRS+=	hello_wsdl

PLIST_VARS+=	ldap ssl
BUILT_AWS !=	pkg_info -Q PKG_OPTIONS aws 2>/dev/null || echo

.if !empty(BUILT_AWS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	LDAP=true
DEMO_DIRS+=		test_ldap
PLIST.ldap=		yes
.endif

.if !empty(BUILT_AWS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	SOCKET=openssl
DEMO_DIRS+=		agent
DEMO_DIRS+=		runme
PLIST.ssl=		yes
.endif

.if !empty(BUILT_AWS:Mgnutls)
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	SOCKET=gnutls
DEMO_DIRS+=		agent
DEMO_DIRS+=		runme
PLIST.ssl=		yes
.endif

do-configure:
	cd ${WRKSRC} && ${GMAKE} setup ${CONFIGURE_ARGS}

do-build:
.for dd in ${DEMO_DIRS}
	cd ${WRKSRC}/demos/${dd} && ${SETENV} ${MAKE_ENV} ${GMAKE}
.endfor

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/examples/aws/demos
.for dd in ${DEMO_DIRS}
	${FIND} ${WRKSRC}/demos/${dd} -type f -perm -0100 \
	-exec ${INSTALL} {} ${DESTDIR}${PREFIX}/share/examples/aws/demos/ \;
.endfor

.include "../../www/aws/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
