# $NetBSD: Makefile,v 1.4 2003/12/20 11:24:51 grant Exp $
#

DISTNAME=		# see Makefile.${OPSYS}.${ARCH}
PKGNAME=		MozillaFirebird-bin-${PKGVER}
WRKSRC=			${WRKDIR}/MozillaFirebird
CATEGORIES=		www
MASTER_SITES=		http://ftp.mozilla.org/pub/firebird/releases/${PKGVER}/ \
			ftp://ftp.mozilla.org/pub/firebird/releases/${PKGVER}/ \
			http://public.planetmirror.com.au/pub/firebird/releases/${PKGVER}/ \
			ftp://public.planetmirror.com.au/pub/firebird/releases/${PKGVER}/

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.mozilla.org/projects/firebird/
COMMENT=		Lightweight gecko-based web browser (binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386 SunOS-5.[789]*-sparc SunOS-5.[89]*-i386

# this package was formerly named "phoenix-linux", and "phoenix-bin".
CONFLICTS+=		phoenix-linux-[0-9]*
CONFLICTS+=		phoenix-bin-[0-9]*

NO_CONFIGURE=		YES
USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		PLATFORM=${PLATFORM}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

do-build:

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/MozillaFirebird.sh > \
		${WRKDIR}/MozillaFirebird.sh

do-install:
	${INSTALL_DATA_DIR} ${MOZILLA_LIB}
	cd ${WRKSRC} && ${PAX} -rw -pm . ${MOZILLA_LIB}
	${INSTALL_SCRIPT} ${WRKDIR}/MozillaFirebird.sh \
		${PREFIX}/bin/MozillaFirebird-${PLATFORM}
	@${RM} -f ${MOZILLA_LIB}/plugins/libnullplugin.so

post-install:
# this build wants exactly 'libgtk-1.2.so.0', etc.
.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
	@cd ${MOZILLA_LIB} && \
	${LN} -s ${PREFIX}/lib/libglib.*so* .;				\
	${LN} -s ${PREFIX}/lib/libgmodule.*so* .;			\
	${LN} -s ${X11PREFIX}/lib/libgdk.*so* .;			\
	${LN} -s ${X11PREFIX}/lib/libgtk.*so* .;			\
	${LN} -s libgtk.so libgtk-1.2.so.0;				\
	${LN} -s libgdk.so libgdk-1.2.so.0;				\
	${LN} -s libglib.so libglib-1.2.so.0;				\
	${LN} -s libgmodule.so libgmodule-1.2.so.0
	
.endif
	@${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	@${ECHO} bin/MozillaFirebird-${PLATFORM} >> ${PLIST_SRC}
	@${FIND} ${MOZILLA_LIB} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	@${FIND} ${MOZILLA_LIB} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.prefs.mk"

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../mk/bsd.pkg.mk"
