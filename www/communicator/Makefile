# $NetBSD: Makefile,v 1.1.1.1 1999/02/22 07:44:48 abs Exp $
#
# Every effort has been made to keep the communicator and navigator
# Makefiles as similar as possible.

BINNAME=	communicator
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
DISTNAME=	${BINNAME}-v45-export.${UNAME}
PKGNAME=	${BINNAME}-4.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netscape.org/pub/communicator/4.5/english/unix/unsupported/${UNAME_SHORT}/complete_install/
ONLY_FOR_ARCHS=	i386 sparc

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://home.netscape.com/browsers/index.html

NO_BUILD=	yes

WRKSRC=         ${WRKDIR}/${BINNAME}-v45.${UNAME}
MOZILLA_HOME=	${PREFIX}/lib/netscape/${PKGNAME}
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	${MKDIR} ${MOZILLA_HOME}/java/classes
	${INSTALL_SCRIPT} ${WRKSRC}/vreg ${MOZILLA_HOME}
.for file in ifc11.jar iiop10.jar jae40.jar java40.jar jio40.jar jsd10.jar \
    ldap10.jar resource.jar scd10.jar
	${INSTALL_DATA} ${WRKSRC}/${file} ${MOZILLA_HOME}/java/classes
.endfor
	cd ${MOZILLA_HOME} ; tar xpzf ${WRKSRC}/nethelp-v45.nif
	cd ${MOZILLA_HOME} ; tar xpzf ${WRKSRC}/netscape-v45.nif
	cd ${MOZILLA_HOME} ; tar xpzf ${WRKSRC}/spellchk-v45.nif

	${SED} -e 's#@@MOZILLA_HOME@@#${MOZILLA_HOME}#g' \
	    <${FILESDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${PREFIX}/bin/${PKGNAME}
	${LN} -sf ${PKGNAME} ${PREFIX}/bin/netscape

.if (${MACHINE_ARCH} == "sparc")
	# Bizarre magic to handle the NIS and DNS versions. Make DNS default.
	@${SED} -e 's#MOZILLA_HOME/netscape#MOZILLA_HOME/netscape_nis#g' \
	    <${WRKDIR}/${BINNAME}.sh >${WRKDIR}/${BINNAME}_nis.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}_nis.sh \
	    ${PREFIX}/bin/${PKGNAME}_nis
	${LN} -sf ${PKGNAME}_nis ${PREFIX}/bin/netscape_nis
	${MV} ${MOZILLA_HOME}/netscape ${MOZILLA_HOME}/netscape_nis
	${MV} ${MOZILLA_HOME}/netscape_dns ${MOZILLA_HOME}/netscape
	${CAT} ${PKGDIR}/PLIST.sparc >>${PLIST_SRC}
.endif
	${CHOWN} -R 0.0 ${MOZILLA_HOME}
	${CHMOD} -R go-w ${MOZILLA_HOME}

	${CAT} ${PKGDIR}/PLIST.post >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
