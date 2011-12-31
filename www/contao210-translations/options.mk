# $NetBSD: options.mk,v 1.19 2011/12/31 01:19:04 taca Exp $

# Not yet ready for Contao 2.10: af ca gl id is no th tl zh
#
CT_SUPPORTED_LANGUAGES=	ar bg bs cs da es fa fi fr gn hr hu it ja ku lt \
			lv nl pl pt rm ro ru sk sl sq sr sv tr uk

CT_TRANSLATIONS.af=	TYPOlight-Afrikaans-v1.zip	# 2008/01/15
CT_TRANSLATIONS.ar=	Contao-Arabic-v3.zip		# 2010/10/30
CT_TRANSLATIONS.bg=	Contao-Bulgarian-v23.zip	# 2011/11/19
CT_TRANSLATIONS.bs=	Contao-Bosnian-v15.zip		# 2010/09/12
CT_TRANSLATIONS.ca=	TYPOlight-Catalan-v4.zip	# 2008/09/24
CT_TRANSLATIONS.cs=	Contao-Czech-v45.zip		# 2011/08/31
CT_TRANSLATIONS.da=	Contao-Danish-v15.zip		# 2010/08/31
CT_TRANSLATIONS.es=	Contao-Spanish-v16.zip		# 2011/01/10
CT_TRANSLATIONS.fa=	Contao-Persian-v10.zip		# 2011/11/18
CT_TRANSLATIONS.fi=	Contao-Finnish-v7.zip		# 2011/09/08
CT_TRANSLATIONS.fr=	Contao-French-v72.zip		# 2011/11/08
CT_TRANSLATIONS.gl=	TYPOlight-Galician-v3.zip	# 2010/03/26
CT_TRANSLATIONS.gn=	Contao-Guarani-v6.zip		# 2011/09/18
CT_TRANSLATIONS.hr=	Contao-Croatian-v16.zip		# 2011/09/02
CT_TRANSLATIONS.hu=	Contao-Hungarian-v12.zip	# 2011/09/14
CT_TRANSLATIONS.id=	TYPOlight-Indonesian-v1.zip	# 2009/01/13
CT_TRANSLATIONS.is=	TYPOlight-Icelandic-v5.zip	# 2010/02/10
CT_TRANSLATIONS.it=	Contao-Italian-v29.zip		# 2011/08/31
CT_TRANSLATIONS.ja=	Contao-Japanese-v72.zip		# 2011/12/10
CT_TRANSLATIONS.ku=	Contao-Kurdish-v5.zip		# 2010/12/24
CT_TRANSLATIONS.lt=	Contao-Lithuanian-v8.zip	# 2010/11/20
CT_TRANSLATIONS.lv=	Contao-Latvian-v33.zip		# 2011/10/12
CT_TRANSLATIONS.nl=	Contao-Dutch-v55.zip		# 2011/08/31
CT_TRANSLATIONS.no=	TYPOlight-Norwegian-v11.zip	# 2009/11/16
CT_TRANSLATIONS.pl=	Contao-Polish-v31.zip		# 2011/10/02
CT_TRANSLATIONS.pt=	Contao-Portuguese-v11.zip	# 2011/11/18
CT_TRANSLATIONS.rm=	Contao-Rhaeto-Romance-v5.zip	# 2011/10/22
CT_TRANSLATIONS.ro=	Contao-Romanian-v13.zip		# 2011/08/22
CT_TRANSLATIONS.ru=	Contao-Russian-v43.zip		# 2011/11/18
CT_TRANSLATIONS.sk=	Contao-Slovak-v9.zip		# 2011/03/18
CT_TRANSLATIONS.sl=	Contao-Slovenian-v11.zip	# 2011/12/30
CT_TRANSLATIONS.sq=	Contao-Albanian-v6.zip		# 2010/12/28
CT_TRANSLATIONS.sr=	Contao-Serbian-v8.zip		# 2011/05/24
CT_TRANSLATIONS.sv=	Contao-Swedish-v61.zip		# 2011/09/12
CT_TRANSLATIONS.th=	TYPOlight-Thai-v2.zip		# 2008/11/23
CT_TRANSLATIONS.tl=	TYPOlight-Tagalog-v1.zip	# 2010/01/29
CT_TRANSLATIONS.tr=	Contao-Turkish-v14.zip		# 2011/03/24
CT_TRANSLATIONS.uk=	Contao-Ukrainian-v15.zip	# 2011/03/09
CT_TRANSLATIONS.zh=	TYPOlight-Chinese-v20.zip	# 2010/01/29

.include "../../www/contao/options.translations.mk"
