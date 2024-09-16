# $NetBSD: Makefile,v 1.65 2024/09/16 00:54:44 scole Exp $

ST_VERSION=	2.37
PKGNAME=	split-thai-${ST_VERSION}
CATEGORIES=	textproc

MAINTAINER=	scole@NetBSD.org
HOMEPAGE=	https://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/
COMMENT=	Emacs library to split UTF-8 Thai text into words and more
# pthai.el, icu dict, swath dict, libreoffice dict
LICENSE=	2-clause-bsd AND mit AND gnu-gpl-v2 AND gnu-lgpl-v3

GITHUB_ICU_TAG=		929cf40ecbf464bb133113995185c7353f2e106d
LIBREOFFICE_VERSION=	7-6-4
LIBREOFFICE_SITE=	https://cgit.freedesktop.org/libreoffice/dictionaries/plain/th_TH/th_TH.dic?h=libreoffice-${LIBREOFFICE_VERSION}
DISTFILES=		split-thai-${ST_VERSION}.tgz thaidict-${GITHUB_ICU_TAG}.txt th_TH-${LIBREOFFICE_VERSION}.dic

SITES.split-thai-${ST_VERSION}.tgz=	${MASTER_SITE_LOCAL}
SITES.thaidict-${GITHUB_ICU_TAG}.txt=	-${MASTER_SITE_GITHUB:=unicode-org/}/icu/raw/${GITHUB_ICU_TAG}/icu4c/source/data/brkitr/dictionaries/thaidict.txt
SITES.th_TH-${LIBREOFFICE_VERSION}.dic=	-${LIBREOFFICE_SITE}

USE_TOOLS=	mkdir cp env awk cat sort uniq grep wc echo
TOOL_DEPENDS+=	libdatrie-[0-9]*:../../devel/libdatrie
TOOL_DEPENDS+=	swath-[0-9]*:../../textproc/swath
DEPENDS+=	emacs>=27.1:../../editors/emacs
DEPENDS+=	sox-[0-9]*:../../audio/sox

ST_SHARE_DIR=		share/split-thai
INSTALLATION_DIRS=	${ST_SHARE_DIR}

ST_SHARE_FILES=		README.txt pthai.el sampledict.txt words

SUBST_CLASSES+=			dictionary-app
SUBST_STAGE.dictionary-app=	pre-configure
SUBST_MESSAGE.dictionary-app=	Fixing dictionary paths.
SUBST_FILES.dictionary-app=	README.txt pthai.el
SUBST_SED.dictionary-app=	-e 's,ST_SHARE_DIR,${PREFIX}/${ST_SHARE_DIR},g'

# there are some dictionary entries with '/' and '"' that emacs
# puthash doesn't like.  skip them with grep so consoles without utf8
# understanding won't be munged when the failure to add prints out an error
pre-build:
	cd ${WRKSRC} && emacs -Q --batch \
		--eval='(setq pthai-bootstrap t)' \
		--eval='(load-file "pthai.el")' \
		--eval='(pthai-twt-save "thai-word-dict")'
	cp ${WRKDIR}/thaidict-${GITHUB_ICU_TAG}.txt ${WRKSRC}/icu-dict
	cp ${WRKDIR}/th_TH-${LIBREOFFICE_VERSION}.dic ${WRKSRC}/th_TH.dic
	cd ${PREFIX}/share/swath && trietool swathdic list | \
		awk '{print $$1}' > ${WRKSRC}/swath-dict
	cd ${WRKSRC} && cat icu-dict swath-dict th_TH.dic thai-word-dict | \
			grep -v '[#0123456789/"]' | sort | uniq > words
.for i in icu-dict thai-word-dict th_TH.dic swath-dict
	@${ECHO} `wc -l ${WRKSRC}/${i} | awk '{print $$1}'` words in ${i}
.endfor
	@${ECHO} `wc -l ${WRKSRC}/words | awk '{print $$1}'` \
		unique words in combined dictionary

do-build:

do-install:
.for i in ${ST_SHARE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/split-thai
.endfor

.include "../../mk/bsd.pkg.mk"
ALL_ENV+=     LC_ALL=en_US.UTF-8
