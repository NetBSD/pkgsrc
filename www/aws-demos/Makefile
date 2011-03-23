# $NetBSD: Makefile,v 1.2 2011/03/23 15:41:55 joerg Exp $
#

DISTNAME=	aws-${AWS_VERSION}
PKGNAME=	aws-demos-${AWS_VERSION}
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
BUILD_DEPENDS+=		gawk-[0-9]*:../../lang/gawk
PATCHDIR=	${.CURDIR}/../../www/aws/patches
DISTINFO_FILE=	${.CURDIR}/../../www/aws/distinfo

MAKE_ENV+=	ADA_PROJECT_PATH=${PREFIX}/lib/gnat

DEMO_DIRS+=	agent
DEMO_DIRS+=	auth
DEMO_DIRS+=	com
DEMO_DIRS+=	dispatch
DEMO_DIRS+=	hello_world
DEMO_DIRS+=	hello_wsdl
DEMO_DIRS+=	hotplug
DEMO_DIRS+=	interoplab
DEMO_DIRS+=	jabber_demo
DEMO_DIRS+=	multiple_sessions
DEMO_DIRS+=	res_demo
DEMO_DIRS+=	runme
DEMO_DIRS+=	soap_demo
DEMO_DIRS+=	soap_disp
DEMO_DIRS+=	soap_vs
DEMO_DIRS+=	split
DEMO_DIRS+=	test_mail
DEMO_DIRS+=	text_input
DEMO_DIRS+=	vh_demo
DEMO_DIRS+=	web_block
DEMO_DIRS+=	web_block_ajax
DEMO_DIRS+=	web_block_ajax_templates
DEMO_DIRS+=	web_elements
DEMO_DIRS+=	web_mail
DEMO_DIRS+=	wps
DEMO_DIRS+=	ws
DEMO_DIRS+=	zdemo
# untested
#PLIST_VARS+=	ldap
#pkgbase := aws
#.include "../../mk/pkg-build-options.mk"
#.if !empty(PKG_BUILD_OPTIONS.aws:Mldap)
#DEMO_DIRS+=	test_ldap
#PLIST.ldap=	yes
#.endif

post-wrapper:
	# We disable at least the wrapper binaries on all GNAT AUX to
	# avoid potential linkage problems
	${RM} ${WRKDIR}/.wrapper/bin/*

do-configure:
	cd ${WRKSRC} && ${SETENV} CC=gnatgcc \
	${GMAKE} setup ${CONFIGURE_ARGS}

do-build:
.for dd in ${DEMO_DIRS}
	cd ${WRKSRC}/demos/${dd} && ${GMAKE}
.endfor

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/examples/aws/demos
.for dd in ${DEMO_DIRS}
	${FIND} ${WRKSRC}/demos/${dd} -type f -perm -0001 \
	-exec ${INSTALL} {} ${DESTDIR}${PREFIX}/share/examples/aws/demos/ \;
.endfor

.include "../../www/aws/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gnatpython/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
