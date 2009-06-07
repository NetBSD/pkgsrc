# $NetBSD: options.mk,v 1.13 2009/06/07 01:16:41 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight-translations

TL_SUPPORTED_LANGUAGES=	af bg ca cs da es fa fr id is it ja lt lv nl no \
			pl pt ro ru sk sq sr sv th tr uk zh

TL_TRANSLATIONS.af=	TYPOlight-Afrikaans-v1.zip	# 2008/01/15
TL_TRANSLATIONS.bg=	TYPOlight-Bulgarian-v12.zip	# 2008/12/09
TL_TRANSLATIONS.ca=	TYPOlight-Catalan-v4.zip	# 2008/09/24
TL_TRANSLATIONS.cs=	TYPOlight-Czech-v3.zip		# 2009/02/26
TL_TRANSLATIONS.da=	TYPOlight-Danish-v6.zip		# 2009/01/25
TL_TRANSLATIONS.es=	TYPOlight-Spanish-v10.zip	# 2008/07/15
TL_TRANSLATIONS.fa=	TYPOlight-Persian-v2.zip	# 2008/06/05
TL_TRANSLATIONS.fr=	TYPOlight-French-v45.zip	# 2009/06/02
TL_TRANSLATIONS.id=	TYPOlight-Indonesian-v1.zip	# 2009/01/13
TL_TRANSLATIONS.is=	TYPOlight-Icelandic-v2.zip	# 2008/01/31
TL_TRANSLATIONS.it=	TYPOlight-Italian-v14.zip	# 2009/05/21
TL_TRANSLATIONS.ja=	TYPOlight-Japanese-v21.zip	# 2009/05/30
TL_TRANSLATIONS.lt=	TYPOlight-Lithuanian-v2.zip	# 2008/04/25
TL_TRANSLATIONS.lv=	TYPOlight-Latvian-v20.zip	# 2009/05/10
TL_TRANSLATIONS.nl=	TYPOlight-Dutch-v31.zip		# 2009/05/18
TL_TRANSLATIONS.no=	TYPOlight-Norwegian-v8.zip	# 2008/09/02
TL_TRANSLATIONS.pl=	TYPOlight-Polish-v22.zip	# 2009/05/18
TL_TRANSLATIONS.pt=	TYPOlight-Portuguese-v6.zip	# 2009/05/24
TL_TRANSLATIONS.ro=	TYPOlight-Romanian-v8.zip	# 2009/03/17
TL_TRANSLATIONS.ru=	TYPOlight-Russian-v22.zip	# 2009/06/05
TL_TRANSLATIONS.sk=	TYPOlight-Slovak-v7.zip		# 2009/05/14
TL_TRANSLATIONS.sq=	TYPOlight-Albanian-v4.zip	# 2008/12/14
TL_TRANSLATIONS.sr=	TYPOlight-Serbian-v5.zip	# 2009/01/24
TL_TRANSLATIONS.sv=	TYPOlight-Swedish-v32.zip	# 2009/05/30
TL_TRANSLATIONS.th=	TYPOlight-Thai-v2.zip		# 2008/11/23
TL_TRANSLATIONS.tr=	TYPOlight-Turkish-v1.zip	# 2008/10/14
TL_TRANSLATIONS.uk=	TYPOlight-Ukrainian-v9.zip	# 2009/05/04
TL_TRANSLATIONS.zh=	TYPOlight-Chinese-v19.zip	# 2008/12/02

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
