# $NetBSD: Makefile,v 1.3 2003/04/14 21:28:10 grant Exp $
#

#DISTNAME=		# see Makefile.${OPSYS}.${ARCH}
PKGNAME=		phoenix-bin-${PKGVER}
WRKSRC=			${WRKDIR}/phoenix
CATEGORIES=		www
MASTER_SITES=		http://komodo.mozilla.org/pub/phoenix/nightly/latest-trunk/

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.mozilla.org/projects/phoenix/
COMMENT=		Lightweight gecko-based web browser (nightly binary pkg)

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386 SunOS-5.[789]*-sparc

CONFLICTS+=		phoenix-linux-[0-9]*

PKGVER!=		date +%Y%m%d
DIST_SUBDIR=		${PKGNAME}
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
USE_PKGINSTALL=		YES

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		PLATFORM=${PLATFORM}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

do-build:

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/phoenix.sh > ${WRKDIR}/phoenix.sh

do-install:
	${INSTALL_DATA_DIR} ${PHOENIX_LIB}
	cd ${WRKSRC} && ${PAX} -rw -pm . ${PHOENIX_LIB}
	${INSTALL_SCRIPT} ${WRKDIR}/phoenix.sh ${PREFIX}/bin/phoenix-${PLATFORM}
	@${FIND} ${PHOENIX_LIB} -type f -print \
		| ${XARGS} ${CHMOD} a+r
	@${FIND} ${PHOENIX_LIB} \( -type f -o -perm +x \) -print \
		| ${XARGS} ${CHMOD} a+rx
	@${FIND} ${PHOENIX_LIB} -type d -print \
		| ${XARGS} ${CHMOD} a+rx

post-install:
	@${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	@${ECHO} bin/phoenix-${PLATFORM} >> ${PLIST_SRC}
	@${FIND} ${PHOENIX_LIB} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
# this build for Solaris wants exactly 'libgtk-1.2.so.0'
.if ${OPSYS} == "SunOS"
	@cd ${PHOENIX_LIB} && \
	${LN} -s ${LOCALBASE}/lib/libglib.so libglib-1.2.so.0; \
	${LN} -s ${X11BASE}/lib/libgdk.so libgdk-1.2.so.0; \
	${LN} -s ${X11BASE}/lib/libgtk.so libgtk-1.2.so.0
.  for _lib_ in glib gdk gtk
	@${ECHO} lib/phoenix-${PLATFORM}/lib${_lib_}-1.2.so.0 >> ${PLIST_SRC}
.  endfor
.endif
	@${FIND} ${PHOENIX_LIB} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

# everything specific to your OS/Arch goes into it's own Makefile
# group together i386, i486, i586 and i686 (for Linux)
ARCH=${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../mk/bsd.pkg.mk"
