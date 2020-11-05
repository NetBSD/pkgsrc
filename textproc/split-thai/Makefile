# $NetBSD: Makefile,v 1.13 2020/11/05 09:09:15 ryoon Exp $

PKGNAME=	split-thai-1.1
PKGREVISION=	1
CATEGORIES=	textproc
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utilities to split UTF-8 Thai text into words
LICENSE=	public-domain AND mit AND gnu-gpl-v2 # code, icu dict, swath dict

# xxx fetching a specific version of a file out of a github project
EXTRACT_SUFX=	# none
GITHUB_ICU_TAG=	61607c27732906d36c5bd4d23ecc092f89f53a2b
DISTFILES=	thaidict-${GITHUB_ICU_TAG}.txt
MASTER_SITES=	-${MASTER_SITE_GITHUB:=unicode-org/}/icu/raw/${GITHUB_ICU_TAG}/icu4c/source/data/brkitr/dictionaries/thaidict.txt

USE_LANGUAGES=	c++11	# darwin needed 11?

USE_TOOLS=	pkg-config mkdir cp sh:run env awk cat sort uniq grep wc echo
USE_TOOLS+=	perl:run
BUILD_DEPENDS+=	libdatrie-[0-9]*:../../devel/libdatrie
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
DEPENDS+=	swath-[0-9]*:../../textproc/swath

REPLACE_PERL=	st-wordbreak tgrep
REPLACE_SH=	st-swath

UTF8_ENV=	env LC_ALL=C.UTF-8

ST_SHARE_DIR=		share/split-thai
ST_SHARE_BIN=		bin
INSTALLATION_DIRS=	${ST_SHARE_BIN} ${ST_SHARE_DIR}

ST_SHARE_FILES=		README.txt thaidict thai-dict.el thai-dict.elc
ST_SHARE_FILES+=	thai-utility.el thai-utility.elc thaidict.tri

# xxx REPLACE_EMACS_SCRIPT
SUBST_CLASSES+=			st-emacs-app
SUBST_STAGE.st-emacs-app=	pre-configure
SUBST_MESSAGE.st-emacs-app=	Fixing emacs script paths.
SUBST_FILES.st-emacs-app=	st-emacs
SUBST_SED.st-emacs-app=		-e 's,!/bin/emacs,!${PREFIX}/bin/emacs,g'

SUBST_CLASSES+=			dictionary-app
SUBST_STAGE.dictionary-app=	pre-configure
SUBST_MESSAGE.dictionary-app=	Fixing dictionary paths.
SUBST_FILES.dictionary-app=	st-emacs st-swath st-wordbreak
SUBST_SED.dictionary-app=	-e 's,ST_SHARE_DIR,${PREFIX}/${ST_SHARE_DIR},g'
SUBST_SED.dictionary-app+=	-e 's,ST_SHARE_BIN,${PREFIX}/${ST_SHARE_BIN},g'

pre-extract:
	mkdir -p ${WRKSRC}
	cd files && cp README.txt st-emacs st-icu.cc st-swath \
		st-wordbreak tgrep thai-utility.el thaidict.abm ${WRKSRC}

post-extract:
	cd ${WRKSRC} && ${UTF8_ENV} emacs --batch \
		-f batch-byte-compile thai-utility.el
	cd ${WRKSRC} && ${UTF8_ENV} emacs --batch -l thai-utility.elc \
		--eval '(thai-word-table-save "emacs-dict")'
	cp ${WRKDIR}/${DISTFILES} ${WRKSRC}/icu-dict
	cd ${PREFIX}/share/swath && \
		${UTF8_ENV} trietool swathdic list | \
		awk '{print $$1}' > ${WRKSRC}/swath-dict
	cd ${WRKSRC} && \
		${UTF8_ENV} cat icu-dict swath-dict emacs-dict | \
			grep -v '#' | sort | uniq > thaidict
	cd ${WRKSRC} && \
		${UTF8_ENV} trietool thaidict add-list -e utf-8 thaidict
	cd ${WRKSRC} && ${UTF8_ENV} emacs --batch -l thai-utility.elc \
		--eval '(thai-word-table-save-defvar "thaidict" "thai-dict.el")'
	cd ${WRKSRC} && ${UTF8_ENV} emacs --batch \
		-f batch-byte-compile thai-dict.el
.for i in emacs-dict icu-dict swath-dict
	@${ECHO} `wc -l ${WRKSRC}/${i} | awk '{print $$1}'` words in ${i}
.endfor
	@${ECHO} `wc -l ${WRKSRC}/thaidict | awk '{print $$1}'` \
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
