# $NetBSD: Makefile,v 1.6 1999/05/25 01:34:53 jlam Exp $
#
# Every effort has been made to keep the communicator and navigator
# Makefiles as similar as possible.

BINNAME=	navigator
NS_VERS=	4.6
NS_VERS_SHORT=	46
#
.if (${MACHINE_ARCH} == "i386")
UNAME=		x86-bsdi-bsd2
UNAME_SHORT=	bsdi21
.elif (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/sunos/usr/lib/ld.so)
IGNORE=You must have SunOS libraries installed - see compat_sunos(8)
.endif
UNAME=		sparc-sun-sunos4.1.3_U1
UNAME_SHORT=	sunos413
.endif
#
DISTNAME=	${BINNAME}-v${NS_VERS_SHORT}-export.${UNAME}
PKGNAME=	${BINNAME}-${NS_VERS}
CATEGORIES=	www
SUB=		english/unix/unsupported/${UNAME_SHORT}/navigator_standalone
MASTER_SITES=	ftp://ftp.netscape.org/pub/communicator/${NS_VERS}/${SUB}/ \
		ftp://sunsite.utk.edu/pub/netscape/communicator/${NS_VERS}/${SUB}/ \
		ftp://ftp-uk.netscape.com/pub/communicator/${SUB}/
ONLY_FOR_PLATFORM=	*-*-{i386,sparc}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.netscape.com/browsers/index.html

NO_BUILD=	yes

WRKSRC=         ${WRKDIR}/${BINNAME}-v${NS_VERS_SHORT}.${UNAME}
MOZILLA_HOME=	${PREFIX}/lib/netscape/${PKGNAME}
PLIST_SRC=	${WRKDIR}/.PLIST_SRC
NS_PLIST_SED=   "s,\$${NS_VERS},${NS_VERS},g"

do-install:
	${SED} -e ${NS_PLIST_SED} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${MKDIR} ${MOZILLA_HOME}/java/classes
	${INSTALL_SCRIPT} ${WRKSRC}/vreg ${MOZILLA_HOME}
.for file in ifc11.jar iiop10.jar jae40.jar java40.jar jio40.jar jsd10.jar \
    ldap30.jar resource.jar scd10.jar
	${INSTALL_DATA} ${WRKSRC}/${file} ${MOZILLA_HOME}/java/classes
.endfor
	cd ${MOZILLA_HOME} ; tar xpzf ${WRKSRC}/nethelp-v${NS_VERS_SHORT}.nif
	cd ${MOZILLA_HOME} ; tar xpzf ${WRKSRC}/netscape-v${NS_VERS_SHORT}.nif

	${SED} -e 's#@@MOZILLA_HOME@@#${MOZILLA_HOME}#g' \
	    <${FILESDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${PKGNAME}

.if (${MACHINE_ARCH} == "sparc")
	# Bizarre magic to handle the NIS and DNS versions. Make DNS default.
	@${SED} -e 's#MOZILLA_HOME/netscape#MOZILLA_HOME/netscape_nis#g' \
	    <${WRKDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}_nis.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}_nis.sh \
	    ${PREFIX}/bin/${PKGNAME}_nis
	${MV} ${MOZILLA_HOME}/netscape ${MOZILLA_HOME}/netscape_nis
	${MV} ${MOZILLA_HOME}/netscape_dns ${MOZILLA_HOME}/netscape
	${SED} -e ${NS_PLIST_SED} ${PKGDIR}/PLIST.sparc >>${PLIST_SRC}
.endif
	${CHOWN} -R 0:0 ${MOZILLA_HOME}
	${CHMOD} -R go-w ${MOZILLA_HOME}

	${SED} -e ${NS_PLIST_SED} ${PKGDIR}/PLIST.post >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
