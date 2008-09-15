# $NetBSD: options.mk,v 1.1.1.1 2008/09/15 09:59:08 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight-translations

TL_SUPPORTED_LANGUAGES=	af bg ca da es fa fr is it ja lt lv nl no \
			pl pt ro ru sk sq sr sv uk

TL_TRANSLATIONS.af=	TYPOlight-Afrikaans-v1.zip
TL_TRANSLATIONS.bg=	TYPOlight-Bulgarian-v8.zip
TL_TRANSLATIONS.ca=	TYPOlight-Catalan-v3.zip
TL_TRANSLATIONS.da=	TYPOlight-Danish-v5.zip
TL_TRANSLATIONS.es=	TYPOlight-Spanish-v10.zip
TL_TRANSLATIONS.fa=	TYPOlight-Persian-v2.zip
TL_TRANSLATIONS.fr=	TYPOlight-French-v30.zip
TL_TRANSLATIONS.is=	TYPOlight-Icelandic-v2.zip
TL_TRANSLATIONS.it=	TYPOlight-Italian-v6.zip
TL_TRANSLATIONS.ja=	TYPOlight-Japanese-v8.zip
TL_TRANSLATIONS.lt=	TYPOlight-Lithuanian-v2.zip
TL_TRANSLATIONS.lv=	TYPOlight-Latvian-v13.zip
TL_TRANSLATIONS.nl=	TYPOlight-Dutch-v23.zip
TL_TRANSLATIONS.no=	TYPOlight-Norwegian-v8.zip
TL_TRANSLATIONS.pl=	TYPOlight-Polish-v17.zip
TL_TRANSLATIONS.pt=	TYPOlight-Portuguese-v2.zip
TL_TRANSLATIONS.ro=	TYPOlight-Romanian-v4.zip
TL_TRANSLATIONS.ru=	TYPOlight-Russian-v16.zip
TL_TRANSLATIONS.sk=	TYPOlight-Slovak-v1.zip
TL_TRANSLATIONS.sq=	TYPOlight-Albanian-v2.zip
TL_TRANSLATIONS.sr=	TYPOlight-Serbian-v2.zip
TL_TRANSLATIONS.sv=	TYPOlight-Swedish-v22.zip
TL_TRANSLATIONS.uk=	TYPOlight-Ukrainian-v3.zip

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
