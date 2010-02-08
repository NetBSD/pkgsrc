# $NetBSD: options.mk,v 1.5 2010/02/08 15:44:48 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight-translations

TL_SUPPORTED_LANGUAGES=	af bg bs ca cs da es fa fi fr hr hu id is it ja lt lv \
			nl no pl pt ro ru sk sl sq sr sv th tl tr uk zh

TL_TRANSLATIONS.af=	TYPOlight-Afrikaans-v1.zip	# 2008/01/15
TL_TRANSLATIONS.bg=	TYPOlight-Bulgarian-v17.zip	# 2009/06/22
TL_TRANSLATIONS.bs=	TYPOlight-Bosnian-v9.zip	# 2010/01/17
TL_TRANSLATIONS.ca=	TYPOlight-Catalan-v4.zip	# 2008/09/24
TL_TRANSLATIONS.cs=	TYPOlight-Czech-v4.zip		# 2010/01/31
TL_TRANSLATIONS.da=	TYPOlight-Danish-v8.zip		# 2009/11/27
TL_TRANSLATIONS.es=	TYPOlight-Spanish-v12.zip	# 2009/07/01
TL_TRANSLATIONS.fa=	TYPOlight-Persian-v2.zip	# 2008/06/05
TL_TRANSLATIONS.fi=	TYPOlight-Finnish-v1.zip	# 2009/11/03
TL_TRANSLATIONS.fr=	TYPOlight-French-v45.zip	# 2009/06/02
TL_TRANSLATIONS.hr=	TYPOlight-Croatian-v3.zip	# 2009/11/02
TL_TRANSLATIONS.hu=	TYPOlight-Hungarian-v3.zip	# 2010/01/17
TL_TRANSLATIONS.id=	TYPOlight-Indonesian-v1.zip	# 2009/01/13
TL_TRANSLATIONS.is=	TYPOlight-Icelandic-v4.zip	# 2009/12/07
TL_TRANSLATIONS.it=	TYPOlight-Italian-v18.zip	# 2009/10/20
TL_TRANSLATIONS.ja=	TYPOlight-Japanese-v24.zip	# 2009/10/23
TL_TRANSLATIONS.lt=	TYPOlight-Lithuanian-v3.zip	# 2009/12/10
TL_TRANSLATIONS.lv=	TYPOlight-Latvian-v23.zip	# 2010/02/04
TL_TRANSLATIONS.nl=	TYPOlight-Dutch-v35.zip		# 2009/10/15
TL_TRANSLATIONS.no=	TYPOlight-Norwegian-v11.zip	# 2009/11/16
TL_TRANSLATIONS.pl=	TYPOlight-Polish-v24.zip	# 2010/02/07
TL_TRANSLATIONS.pt=	TYPOlight-Portuguese-v7.zip	# 2009/11/01
TL_TRANSLATIONS.ro=	TYPOlight-Romanian-v8.zip	# 2009/03/17
TL_TRANSLATIONS.ru=	TYPOlight-Russian-v24.zip	# 2010/02/05
TL_TRANSLATIONS.sk=	TYPOlight-Slovak-v8.zip		# 2009/08/15
TL_TRANSLATIONS.sl=	TYPOlight-Slovenian-v5.zip	# 2009/06/20
TL_TRANSLATIONS.sq=	TYPOlight-Albanian-v4.zip	# 2008/12/14
TL_TRANSLATIONS.sr=	TYPOlight-Serbian-v6.zip	# 2009/06/09
TL_TRANSLATIONS.sv=	TYPOlight-Swedish-v40.zip	# 2010/02/04
TL_TRANSLATIONS.th=	TYPOlight-Thai-v2.zip		# 2008/11/23
TL_TRANSLATIONS.tl=	TYPOlight-Tagalog-v1.zip	# 2010/01/29
TL_TRANSLATIONS.tr=	TYPOlight-Turkish-v5.zip	# 2009/12/28
TL_TRANSLATIONS.uk=	TYPOlight-Ukrainian-v12.zip	# 2009/11/02
TL_TRANSLATIONS.zh=	TYPOlight-Chinese-v20.zip	# 2010/01/29

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
	http://www.typolight.org/download.html?iso=${l}&file=tl_files/languages/${l}/
PLIST_SRC+=	PLIST.${l}
.endfor
