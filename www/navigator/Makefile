# $NetBSD: Makefile,v 1.19 1999/09/04 16:38:30 jlam Exp $
#
# Every effort has been made to keep the communicator and navigator
# Makefiles as similar as possible.

BINNAME=	navigator
NS_VERS=	4.61
NS_VERS_SHORT=	461
NS_ENCRYPTION?=	export

BUILD_DEFS+=	NS_ENCRYPTION

#
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
DISTUNAME=	sparc-sun-solaris2.5.1
DIST_DIR_NAME=	supported/sunos551
WRKNAME=	sparc-sun-solaris2.5.1
.elif (${MACHINE_ARCH} == "alpha")
.if !exists(/emul/osf1/sbin/loader)
IGNORE=	requires Digital UNIX libraries - see compat_osf1(8)
.endif
DISTUNAME=	alpha-dec-osf4.0
DIST_DIR_NAME=	supported/dec_unix40
WRKNAME=	alpha-dec-osf4.0
.elif (${MACHINE_ARCH} == "i386")
.if !exists(/emul/linux/lib/ld-linux.so.2)
IGNORE=	requires Linux glibc2 libraries - see compat_linux(8)
.endif
DISTUNAME=	x86-unknown-linuxglibc2.0
DIST_DIR_NAME=	supported/linux20_glibc2
WRKNAME=	x86-unknown-linux2.0
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/sunos/usr/lib/ld.so)
IGNORE=	requires SunOS libraries - see compat_sunos(8)
.endif
DISTUNAME=	sparc-sun-sunos4.1.3_U1
DIST_DIR_NAME=	unsupported/sunos413
WRKNAME=	${DISTUNAME}
.endif
#
DISTNAME=	${BINNAME}-v${NS_VERS_SHORT}-${NS_ENCRYPTION}.${DISTUNAME}
PKGNAME=	${BINNAME}-${NS_VERS}
CATEGORIES=	www
SUB=		english/${NS_VERS}/unix/${DIST_DIR_NAME}/navigator_standalone
MASTER_SITES=	ftp://ftp.netscape.org/pub/communicator/${SUB}/ \
		ftp://sunsite.utk.edu/pub/netscape/communicator/${SUB}/ \
		ftp://ftp-uk.netscape.com/pub/communicator/${SUB}/ \
		ftp.informatik.rwth-aachen.de:/pub/mirror/ftp.netscape.com/pub/communicator/${SUB}/
ONLY_FOR_PLATFORM= *-*-alpha *-*-i386 *-*-sparc

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.netscape.com/browsers/index.html

NO_BUILD=	yes

WRKSRC=         ${WRKDIR}/${BINNAME}-v${NS_VERS_SHORT}.${WRKNAME}
MOZILLA_HOME=	${PREFIX}/lib/netscape/${PKGNAME}
NS_PLUGINS_DIR=	${PREFIX}/lib/netscape/plugins

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${PKGDIR}/PLIST.pre \
		${PKGDIR}/PLIST.${LOWER_OPSYS}-${MACHINE_ARCH} \
		${PKGDIR}/PLIST.post
PLIST_SUBST+=	NS_VERS=${NS_VERS}

.if (${NS_ENCRYPTION} == "us")
MASTER_SITES=
RESTRICTED=		"128-bit key strong encryption; export-controlled"
MIRROR_DISTFILE=	no
ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386
DOWNLOAD=		http://www.netscape.com/download/

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "    The 128-bit key strong encryption version of"; \
	    ${ECHO_MSG} "    Netscape for this platform must be fetched"; \
	    ${ECHO_MSG} "    into \"${DISTDIR}\" from the following URL:"; \
	    ${ECHO_MSG} "    ${DOWNLOAD}"; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi
.endif

do-install:
	${MKDIR} ${MOZILLA_HOME}/java/classes
	${INSTALL_SCRIPT} ${WRKSRC}/vreg ${MOZILLA_HOME}
.for file in ifc11.jar iiop10.jar jae40.jar java40.jar jio40.jar jsd10.jar \
    ldap30.jar resource.jar scd10.jar
	${INSTALL_DATA} ${WRKSRC}/${file} ${MOZILLA_HOME}/java/classes
.endfor
	cd ${MOZILLA_HOME} ; ${GTAR} xpzf ${WRKSRC}/nethelp-v${NS_VERS_SHORT}.nif
	cd ${MOZILLA_HOME} ; ${GTAR} xpzf ${WRKSRC}/netscape-v${NS_VERS_SHORT}.nif

	${SED} -e 's#@@MOZILLA_HOME@@#${MOZILLA_HOME}#g' \
	       -e 's#@@NS_PLUGINS_DIR@@#${NS_PLUGINS_DIR}#g' \
	    <${FILESDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${PKGNAME}
	${RM} -f ${PREFIX}/bin/${BINNAME}
	${LN} -sf ${PKGNAME} ${PREFIX}/bin/${BINNAME}

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
	# Bizarre magic to handle the NIS and DNS versions. Make DNS default.
	@${SED} -e 's#MOZILLA_HOME/netscape#MOZILLA_HOME/netscape_nis#g' \
	    <${WRKDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}_nis.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}_nis.sh \
	    ${PREFIX}/bin/${PKGNAME}_nis
	${MV} ${MOZILLA_HOME}/netscape ${MOZILLA_HOME}/netscape_nis
	${MV} ${MOZILLA_HOME}/netscape_dns ${MOZILLA_HOME}/netscape
.endif
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}

	${CHOWN} -R 0:0 ${MOZILLA_HOME}
	${CHMOD} -R go-w ${MOZILLA_HOME}

.include "../../mk/bsd.pkg.mk"
