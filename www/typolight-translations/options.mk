# $NetBSD: options.mk,v 1.6 2008/11/07 15:16:02 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight-translations

TL_SUPPORTED_LANGUAGES=	af bg ca da es fa fr is it ja lt lv nl no \
			pl pt ro ru sk sq sr sv tr uk

TL_TRANSLATIONS.af=	TYPOlight-Afrikaans-v1.zip
TL_TRANSLATIONS.bg=	TYPOlight-Bulgarian-v11.zip
TL_TRANSLATIONS.ca=	TYPOlight-Catalan-v4.zip
TL_TRANSLATIONS.da=	TYPOlight-Danish-v5.zip
TL_TRANSLATIONS.es=	TYPOlight-Spanish-v10.zip
TL_TRANSLATIONS.fa=	TYPOlight-Persian-v2.zip
TL_TRANSLATIONS.fr=	TYPOlight-French-v33.zip
TL_TRANSLATIONS.is=	TYPOlight-Icelandic-v2.zip
TL_TRANSLATIONS.it=	TYPOlight-Italian-v8.zip
TL_TRANSLATIONS.ja=	TYPOlight-Japanese-v10.zip
TL_TRANSLATIONS.lt=	TYPOlight-Lithuanian-v2.zip
TL_TRANSLATIONS.lv=	TYPOlight-Latvian-v15.zip
TL_TRANSLATIONS.nl=	TYPOlight-Dutch-v25.zip
TL_TRANSLATIONS.no=	TYPOlight-Norwegian-v8.zip
TL_TRANSLATIONS.pl=	TYPOlight-Polish-v19.zip
TL_TRANSLATIONS.pt=	TYPOlight-Portuguese-v3.zip
TL_TRANSLATIONS.ro=	TYPOlight-Romanian-v4.zip
TL_TRANSLATIONS.ru=	TYPOlight-Russian-v17.zip
TL_TRANSLATIONS.sk=	TYPOlight-Slovak-v1.zip
TL_TRANSLATIONS.sq=	TYPOlight-Albanian-v3.zip
TL_TRANSLATIONS.sr=	TYPOlight-Serbian-v3.zip
TL_TRANSLATIONS.sv=	TYPOlight-Swedish-v24.zip
TL_TRANSLATIONS.tr=	TYPOlight-Turkish-v1.zip
TL_TRANSLATIONS.uk=	TYPOlight-Ukrainian-v5.zip

.for l in ${TL_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=	lang-${l}
PKG_SUGGESTED_OPTIONS+=	lang-${l}
.endfor

.include "../../mk/bsd.options.mk"

.for l in ${PKG_OPTIONS:Mlang-*}
TL_LANGUAGES+=	${l:S/^lang-//1}
.endfor

.for l in ${TL_LANGUAGES}
TL_DISTFILES+=	${TL_TRANSLATIONS.${l}}
SITES.${TL_TRANSLATIONS.${l}}= \
	http://www.typolight.org/download-translations.html?iso=${l}&file=tl_files/languages/${l}/
PLIST_SRC+=	PLIST.${l}
.endfor
