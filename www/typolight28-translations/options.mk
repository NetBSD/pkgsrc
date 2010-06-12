# $NetBSD: options.mk,v 1.18.2.1 2010/06/12 15:59:49 tron Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.typolight-translations

TL_SUPPORTED_LANGUAGES=	af bg bs ca cs da es fa fi fr gl hr hu id is it ja \
			lt lv nl no pl pt ro ru sk sl sq sr sv th tl tr uk zh

TL_TRANSLATIONS.af=	TYPOlight-Afrikaans-v1.zip	# 2008/01/15
TL_TRANSLATIONS.bg=	TYPOlight-Bulgarian-v18.zip	# 2010/02/18
TL_TRANSLATIONS.bs=	TYPOlight-Bosnian-v10.zip	# 2010/03/18
TL_TRANSLATIONS.ca=	TYPOlight-Catalan-v4.zip	# 2008/09/24
TL_TRANSLATIONS.cs=	TYPOlight-Czech-v19.zip		# 2010/06/03
TL_TRANSLATIONS.da=	TYPOlight-Danish-v10.zip	# 2010/05/16
TL_TRANSLATIONS.es=	TYPOlight-Spanish-v13.zip	# 2010/06/06
TL_TRANSLATIONS.fa=	TYPOlight-Persian-v4.zip	# 2010/05/12
TL_TRANSLATIONS.fi=	TYPOlight-Finnish-v1.zip	# 2009/11/03
TL_TRANSLATIONS.fr=	TYPOlight-French-v53.zip	# 2010/04/14
TL_TRANSLATIONS.gl=	TYPOlight-Galician-v3.zip	# 2010/03/26
TL_TRANSLATIONS.hr=	TYPOlight-Croatian-v5.zip	# 2010/05/07
TL_TRANSLATIONS.hu=	TYPOlight-Hungarian-v4.zip	# 2010/05/04
TL_TRANSLATIONS.id=	TYPOlight-Indonesian-v1.zip	# 2009/01/13
TL_TRANSLATIONS.is=	TYPOlight-Icelandic-v5.zip	# 2010/02/10
TL_TRANSLATIONS.it=	TYPOlight-Italian-v23.zip	# 2010/04/15
TL_TRANSLATIONS.ja=	TYPOlight-Japanese-v29.zip	# 2010/05/04
TL_TRANSLATIONS.lt=	TYPOlight-Lithuanian-v4.zip	# 2010/04/14
TL_TRANSLATIONS.lv=	TYPOlight-Latvian-v24.zip	# 2010/04/20
TL_TRANSLATIONS.nl=	TYPOlight-Dutch-v41.zip		# 2010/05/27
TL_TRANSLATIONS.no=	TYPOlight-Norwegian-v11.zip	# 2009/11/16
TL_TRANSLATIONS.pl=	TYPOlight-Polish-v27.zip	# 2010/02/19
TL_TRANSLATIONS.pt=	TYPOlight-Portuguese-v7.zip	# 2009/11/01
TL_TRANSLATIONS.ro=	TYPOlight-Romanian-v8.zip	# 2009/03/17
TL_TRANSLATIONS.ru=	TYPOlight-Russian-v32.zip	# 2010/05/10
TL_TRANSLATIONS.sk=	TYPOlight-Slovak-v8.zip		# 2009/08/15
TL_TRANSLATIONS.sl=	TYPOlight-Slovenian-v6.zip	# 2010/03/12
TL_TRANSLATIONS.sq=	TYPOlight-Albanian-v4.zip	# 2008/12/14
TL_TRANSLATIONS.sr=	TYPOlight-Serbian-v7.zip	# 2010/05/10
TL_TRANSLATIONS.sv=	TYPOlight-Swedish-v48.zip	# 2010/06/06
TL_TRANSLATIONS.th=	TYPOlight-Thai-v2.zip		# 2008/11/23
TL_TRANSLATIONS.tl=	TYPOlight-Tagalog-v1.zip	# 2010/01/29
TL_TRANSLATIONS.tr=	TYPOlight-Turkish-v10.zip	# 2010/06/06
TL_TRANSLATIONS.uk=	TYPOlight-Ukrainian-v13.zip	# 2010/15/14
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
	http://www.contao.org/download.html?iso=${l}&file=tl_files/languages/${l}/
PLIST_SRC+=	PLIST.${l}
.endfor
