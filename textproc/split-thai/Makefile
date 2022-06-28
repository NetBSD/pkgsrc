# $NetBSD: Makefile,v 1.37 2022/06/28 11:36:49 wiz Exp $

ST_VERSION=	2.15
PKGNAME=	split-thai-${ST_VERSION}
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	scole@NetBSD.org
HOMEPAGE=	https://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/
COMMENT=	Utilities and an emacs library to split UTF-8 Thai text into words
# pthai.el, other code, icu dict, swath dict, libreoffice dict
LICENSE=	2-clause-bsd AND public-domain AND mit AND gnu-gpl-v2 AND gnu-lgpl-v3

GITHUB_ICU_TAG=		61607c27732906d36c5bd4d23ecc092f89f53a2b
LIBREOFFICE_VERSION=	7-2-0
LIBREOFFICE_SITE=	https://cgit.freedesktop.org/libreoffice/dictionaries/plain/th_TH/th_TH.dic?h=libreoffice-${LIBREOFFICE_VERSION}
DISTFILES=		split-thai-${ST_VERSION}.tgz thaidict-${GITHUB_ICU_TAG}.txt th_TH-${LIBREOFFICE_VERSION}.dic

SITES.split-thai-${ST_VERSION}.tgz=	${MASTER_SITE_LOCAL}
SITES.thaidict-${GITHUB_ICU_TAG}.txt=	-${MASTER_SITE_GITHUB:=unicode-org/}/icu/raw/${GITHUB_ICU_TAG}/icu4c/source/data/brkitr/dictionaries/thaidict.txt
SITES.th_TH-${LIBREOFFICE_VERSION}.dic=	-${LIBREOFFICE_SITE}

# darwin needed 11 to compile icu program?
USE_LANGUAGES=	c++11

USE_TOOLS=	pkg-config mkdir cp sh:run env awk cat sort uniq grep wc echo
USE_TOOLS+=	perl:run
BUILD_DEPENDS+=	libdatrie-[0-9]*:../../devel/libdatrie
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
DEPENDS+=	swath-[0-9]*:../../textproc/swath
DEPENDS+=	sox-[0-9]*:../../audio/sox

REPLACE_PERL=	st-wordbreak tgrep
REPLACE_SH=	st-swath

UTF8_ENV=	env LC_ALL=C.UTF-8

ST_SHARE_DIR=		share/split-thai
ST_SHARE_BIN=		bin
INSTALLATION_DIRS=	${ST_SHARE_BIN} ${ST_SHARE_DIR}

ST_SHARE_FILES=		README.txt pthai.el sampledict.txt words words.tri

# xxx REPLACE_EMACS_SCRIPT
SUBST_CLASSES+=			st-emacs-app
SUBST_STAGE.st-emacs-app=	pre-configure
SUBST_MESSAGE.st-emacs-app=	Fixing emacs script paths.
SUBST_FILES.st-emacs-app=	st-emacs
SUBST_SED.st-emacs-app=		-e 's,!/bin/emacs,!${PREFIX}/bin/emacs,g'

SUBST_CLASSES+=			dictionary-app
SUBST_STAGE.dictionary-app=	pre-configure
SUBST_MESSAGE.dictionary-app=	Fixing dictionary paths.
SUBST_FILES.dictionary-app=	st-emacs st-swath st-wordbreak pthai.el
SUBST_SED.dictionary-app=	-e 's,ST_SHARE_DIR,${PREFIX}/${ST_SHARE_DIR},g'
SUBST_SED.dictionary-app+=	-e 's,ST_SHARE_BIN,${PREFIX}/${ST_SHARE_BIN},g'

# there are some dictionary entries with '/' and '"' that emacs
# puthash doesn't like.  skip them with grep so consoles without utf8
# understanding won't be munged when the failure to add prints out an error
pre-build:
	cd ${WRKSRC} && ${UTF8_ENV} emacs --batch \
		--eval='(setq pthai-bootstrap t)' \
		--eval='(load-file "pthai.el")' \
		--eval='(pthai-twt-save "thai-word-dict")'
	cp ${WRKDIR}/thaidict-${GITHUB_ICU_TAG}.txt ${WRKSRC}/icu-dict
	cp ${WRKDIR}/th_TH-${LIBREOFFICE_VERSION}.dic ${WRKSRC}/th_TH.dic
	cd ${PREFIX}/share/swath && \
		${UTF8_ENV} trietool swathdic list | \
		awk '{print $$1}' > ${WRKSRC}/swath-dict
	cd ${WRKSRC} && \
		${UTF8_ENV} cat icu-dict swath-dict th_TH.dic thai-word-dict | \
			grep -v '[#0123456789/"]' | sort | uniq > words
	cd ${WRKSRC} && \
		${UTF8_ENV} trietool words add-list -e utf-8 words
.for i in icu-dict thai-word-dict th_TH.dic swath-dict
	@${ECHO} `wc -l ${WRKSRC}/${i} | awk '{print $$1}'` words in ${i}
.endfor
	@${ECHO} `wc -l ${WRKSRC}/words | awk '{print $$1}'` \
		unique words in combined dictionary

do-build:
	cd ${WRKSRC} &&	\
		${CXX} ${CPPFLAGS} -o st-icu st-icu.cc \
		`pkg-config --libs --cflags icu-io`

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/st-emacs ${WRKSRC}/st-swath \
		${WRKSRC}/st-wordbreak ${WRKSRC}/tgrep ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/st-icu ${DESTDIR}${PREFIX}/bin
.for i in ${ST_SHARE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/split-thai
.endfor

.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
