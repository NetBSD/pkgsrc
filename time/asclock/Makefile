# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:12 wiz Exp $
#

DISTNAME=	asclock-classic-1.0
PKGNAME=	asclock-1.0
CATEGORIES=	x11 time
MASTER_SITES=	http://www.asclock.org/tar/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.asclock.org/

USE_IMAKE=	YES
USE_XPM=	YES

LANGUAGES=	en de pt nl no it sv es hu br fr cs ru uk sl id da

WRKSRC=		${WRKDIR}/asclock1.0
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

# Translate to two-letter abbreviations in /usr/share/misc/language.
#
post-extract:
	${MV} ${WRKSRC}/english ${WRKSRC}/en
	${MV} ${WRKSRC}/german ${WRKSRC}/de
	${MV} ${WRKSRC}/portuguese ${WRKSRC}/pt
	${MV} ${WRKSRC}/dutch ${WRKSRC}/nl
	${MV} ${WRKSRC}/norwegian ${WRKSRC}/no
	${MV} ${WRKSRC}/italian ${WRKSRC}/it
	${MV} ${WRKSRC}/swedish ${WRKSRC}/sv
	${MV} ${WRKSRC}/spanish ${WRKSRC}/es
	${MV} ${WRKSRC}/hungarian ${WRKSRC}/hu
	${MV} ${WRKSRC}/breton ${WRKSRC}/br
	${MV} ${WRKSRC}/french ${WRKSRC}/fr
	${MV} ${WRKSRC}/czech ${WRKSRC}/cs
	${MV} ${WRKSRC}/russian ${WRKSRC}/ru
	${MV} ${WRKSRC}/ukrainian ${WRKSRC}/uk
	${MV} ${WRKSRC}/slovene ${WRKSRC}/sl
	${MV} ${WRKSRC}/indonesian ${WRKSRC}/id
	${MV} ${WRKSRC}/danish ${WRKSRC}/da

pre-configure:
	${LN} -sf ./en/month.xpm ${WRKSRC}/month.xpm
	${LN} -sf ./en/weekday.xpm ${WRKSRC}/weekday.xpm
	${LN} -sf ./xpm/color.xpm ${WRKSRC}/clk.xpm

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${FILESDIR}/asclock.sh > ${WRKDIR}/asclock.sh
	${INSTALL_SCRIPT} ${WRKDIR}/asclock.sh ${PREFIX}/bin/asclock
	${INSTALL_PROGRAM} ${WRKSRC}/asclock ${PREFIX}/libexec/asclock-classic
	${INSTALL_DATA} ${WRKSRC}/asclock.0 ${PREFIX}/man/cat1/asclock.0
	${INSTALL_DATA_DIR} ${PREFIX}/share/asclock-classic
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
.for LANGUAGE in ${LANGUAGES}
	${INSTALL_DATA_DIR} ${PREFIX}/share/asclock-classic/${LANGUAGE}
	cd ${WRKSRC}/${LANGUAGE}; ${INSTALL_DATA} month.xpm weekday.xpm \
		${PREFIX}/share/asclock-classic/${LANGUAGE}
	@${ECHO} share/asclock-classic/${LANGUAGE}/month.xpm >> ${PLIST_SRC}
	@${ECHO} share/asclock-classic/${LANGUAGE}/weekday.xpm >> ${PLIST_SRC}
	@${ECHO} @dirrm share/asclock-classic/${LANGUAGE} >> ${PLIST_SRC}
.endfor
	@${ECHO} @dirrm share/asclock-classic >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
