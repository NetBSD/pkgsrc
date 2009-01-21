# $NetBSD: options.mk,v 1.7 2009/01/21 14:03:44 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.drupal-translations

# Select official release or beta versions which contains correct
# directory structure.
#
# Broken directory structure: eo vi
# Development version only: ar fr nn pt th tr
# Empty, LICENSE.it.txt only: it
DL_SUPPORTED_LANGUAGES=	cs da de el es fi fr gu he hu it ja ko lt nb nl \
			pl pt-br ro ru sk sv uk-ua zh-cn zh-tw

DL_TRANSLATIONS.cs=	cs-6.x-1.9.tar.gz		# 2008/09/29
DL_TRANSLATIONS.da=	da-6.x-1.0.tar.gz		# 2008/08/25
DL_TRANSLATIONS.de=	de-6.x-1.0-rc1.tar.gz		# 2008/08/16
DL_TRANSLATIONS.el=	el-6.x-1.0-beta1.tar.gz		# 2008/04/05
#DL_TRANSLATIONS.eo=	eo-6.x-1.0.tar.gz		# 2008/05/31
DL_TRANSLATIONS.es=	es-6.x-1.2.tar.gz		# 2008/11/17
DL_TRANSLATIONS.fi=	fi-6.x-1.0.tar.gz		# 2008/09/10
DL_TRANSLATIONS.fr=	fr-6.x-1.0.tar.gz		# 2009/01/13
DL_TRANSLATIONS.gu=	gu-6.x-1.0.tar.gz		# 2008/06/11
DL_TRANSLATIONS.he=	he-6.x-1.0.tar.gz		# 2008/03/14
DL_TRANSLATIONS.hu=	hu-6.x-1.0.tar.gz		# 2008/02/15
DL_TRANSLATIONS.it=	it-6.x-1.4.tar.gz		# 2008/12/07
DL_TRANSLATIONS.ja=	ja-6.x-1.2.tar.gz		# 2008/04/12
DL_TRANSLATIONS.ko=	ko-6.x-1.2.tar.gz		# 2008/12/12
DL_TRANSLATIONS.lt=	lt-6.x-1.2.tar.gz		# 2008/02/26
DL_TRANSLATIONS.nb=	nb-6.x-1.0.tar.gz		# 2008/10/10
DL_TRANSLATIONS.nl=	nl-6.x-1.3.tar.gz		# 2009/01/18
#DL_TRANSLATIONS.nl=	nn-6.x-1.x-dev.tar.gz		# 2008/05/13
DL_TRANSLATIONS.pl=	pl-6.x-0.3.tar.gz		# 2008/09/08
DL_TRANSLATIONS.pt-br=	pt-br-6.x-1.0-rc5.tar.gz	# 2008/08/28
#DL_TRANSLATIONS.pt-br=	pt-pt-6.x-1.x-dev.tar.gz	# 2008/11/30
DL_TRANSLATIONS.ro=	ro-6.x-1.1.tar.gz		# 2008/02/21
DL_TRANSLATIONS.ru=	ru-6.x-1.1.tar.gz		# 2009/01/02
DL_TRANSLATIONS.sk=	sk-6.x-1.1.tar.gz		# 2009/01/04
DL_TRANSLATIONS.sv=	sv-6.x-1.1.tar.gz		# 2008/09/25
#DL_TRANSLATIONS.th=	th-6.x-1.x-dev.tar.gz		# 2008/05/22
#DL_TRANSLATIONS.tr=	tr-6.x-1.x-dev.tar.gz		# 2008/05/29
DL_TRANSLATIONS.uk-ua=	uk-ua-6.x-1.2-beta3.tar.gz	# 2008/10/03
#DL_TRANSLATIONS.vi=	sv-6.x-1.x-dev.tar.gz		# 2008/03/26
DL_TRANSLATIONS.zh-cn=	zh-hans-6.x-1.0.tar.gz		# 2008/06/01
DL_TRANSLATIONS.zh-tw=	zh-hant-6.x-1.1.tar.gz		# 2008/05/14

.for l in ${DL_SUPPORTED_LANGUAGES}
PKG_SUPPORTED_OPTIONS+=	lang-${l}
PKG_SUGGESTED_OPTIONS+=	lang-${l}
.endfor

.include "../../mk/bsd.options.mk"

.for l in ${PKG_OPTIONS:Mlang-*}
DL_LANGUAGES+=	${l:S/^lang-//1}
.endfor

.for l in ${DL_LANGUAGES}
DL_DISTFILES+=	${DL_TRANSLATIONS.${l}}
PLIST_SRC+=	PLIST.${l}
.endfor
PLIST_SRC+=	PLIST.common_end
