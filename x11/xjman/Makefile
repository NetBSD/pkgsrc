# $NetBSD: Makefile,v 1.16 2015/07/04 16:18:43 joerg Exp $

DISTNAME=	xjman-0.5
PKGREVISION=	2
CATEGORIES=	japanese x11
MASTER_SITES=	http://xjman.dsl.gr.jp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xjman.dsl.gr.jp/
COMMENT=	Japanized X manual from "The X Japanese Documentation Project"

DEPENDS+=	ja-man-[0-9]*:../../misc/ja-man

WRKSRC=		${WRKDIR}/man/ja_JP.eucJP
PLIST_SRC=	${WRKDIR}/PLIST
XJMANDIR=	man/ja_JP.EUC
MAKE_ENV+=	XJMANDIR=${XJMANDIR:Q}

USE_BSD_MAKEFILE=	yes

NO_CONFIGURE=	yes

MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.prefs.mk"

post-extract:
.for f in Makefile Makefile.inc
	@${CP} ${FILESDIR}/${f} ${WRKSRC}
.endfor

pre-build:
.for dir in man1 man3 man5
	@(cd ${WRKSRC}/${dir};					\
	  for file in *; do					\
		f=`${ECHO} $$file|${SED} -e 's|x$$||'`;		\
		mlink=`head -1 $$file|${GREP} '^\.so man./'|	\
			${SED} -e 's|.*man./\(.*\)x|\1|'`; 	\
		if [ "$$mlink" = "" ]; then			\
			${ECHO} "MAN+= $$f" >> Makefile;	\
			${MV} $$file $$f;			\
		else						\
			${ECHO} "MLINKS+= $$mlink $$f" >> Makefile;	\
			${SED} -e 's|x$$||' $$file > $$f;	\
			${RM} $$file;				\
		fi;						\
	  done;							\
	  ${ECHO} ".include <bsd.prog.mk>" >> Makefile;		\
	  )
.endfor

MKCATPAGES?=	yes

post-build:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(cd ${WRKSRC};						\
	  ${FIND} man1/*.1 man3/*.3 man5/*.5 -type f -print |	\
		${SED} -e 's|^|${XJMANDIR}/|' | ${SORT} >> ${PLIST_SRC})
.if ${MKCATPAGES} != no
	@(cd ${WRKSRC};						\
	  ${FIND} man1/*.1 man3/*.3 man5/*.5 -type f -print |	\
		${SED} -e 's|^|${XJMANDIR}/|'			\
		       -e 's|man[135]\(/.*\)\.\([135]\)$$|cat\2\1.0|' | \
		${SORT} >> ${PLIST_SRC})
.endif

INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/cat1 ${PKGMANDIR}/ja_JP.EUC/man1 \
			${PKGMANDIR}/ja_JP.EUC/cat3 ${PKGMANDIR}/ja_JP.EUC/man3 \
			${PKGMANDIR}/ja_JP.EUC/cat5 ${PKGMANDIR}/ja_JP.EUC/man5 \
			share/doc/xjman

post-install:
.for i in COPYRIGHT COPYRIGHT.XJDP
	@${INSTALL_DATA} ${FILESDIR}/${i} ${DESTDIR}${PREFIX}/share/doc/xjman
.endfor
	@${INSTALL_DATA} ${WRKDIR}/man/README ${DESTDIR}${PREFIX}/share/doc/xjman

.include "../../mk/bsd.pkg.mk"
