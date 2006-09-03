# $NetBSD: Makefile,v 1.11 2006/09/03 00:56:30 wiz Exp $

DISTNAME=	xjman-0.5
PKGREVISION=	1
CATEGORIES=	japanese x11
MASTER_SITES=	http://xjman.dsl.gr.jp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xjman.dsl.gr.jp/
COMMENT=	Japanized X manual from "The X Japanese Documentation Project"

DEPENDS+=	ja-man-[0-9]*:../../misc/ja-man

WRKSRC=		${WRKDIR}/man/ja_JP.eucJP
USE_X11BASE=	yes
PLIST_SRC=	${WRKDIR}/PLIST
XJMANDIR=	man/ja_JP.EUC
MAKE_ENV+=	XJMANDIR=${XJMANDIR:Q}

NO_CONFIGURE=	yes

MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/x11.buildlink3.mk"

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

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xjman
.for i in COPYRIGHT COPYRIGHT.XJDP
	@${INSTALL_DATA} ${FILESDIR}/${i} ${PREFIX}/share/doc/xjman
.endfor
	@${INSTALL_DATA} ${WRKDIR}/man/README ${PREFIX}/share/doc/xjman

.include "../../mk/bsd.pkg.mk"
