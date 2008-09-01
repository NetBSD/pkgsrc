# $NetBSD: options.mk,v 1.1 2008/09/01 15:16:25 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.drupal-translations

# Broken directory structure: eo vi
# development version only: ar fr nb nn pt sv th tr
DL_SUPPORTED_LANGUAGES=	cs de el es fi gu he hu ja lt nl pt-br ro sk \
			zh-cn zh-tw

DL_TRANSLATIONS.cs=	cs-6.x-1.8.tar.gz
DL_TRANSLATIONS.da=	da-6.x-1.0.tar.gz
DL_TRANSLATIONS.de=	de-6.x-1.0-rc1.tar.gz
DL_TRANSLATIONS.el=	el-6.x-1.0-beta1.tar.gz
DL_TRANSLATIONS.es=	es-6.x-1.0.tar.gz
DL_TRANSLATIONS.fi=	fi-6.x-1.0-rc.tar.gz
DL_TRANSLATIONS.gu=	gu-6.x-1.0.tar.gz
DL_TRANSLATIONS.he=	he-6.x-1.0.tar.gz
DL_TRANSLATIONS.hu=	hu-6.x-1.0.tar.gz
DL_TRANSLATIONS.ja=	ja-6.x-1.2.tar.gz
DL_TRANSLATIONS.lt=	lt-6.x-1.2.tar.gz
DL_TRANSLATIONS.nl=	nl-6.x-1.1.tar.gz
DL_TRANSLATIONS.pt-br=	pt-br-6.x-1.0-rc5.tar.gz
DL_TRANSLATIONS.ro=	ro-6.x-1.1.tar.gz
DL_TRANSLATIONS.sk=	sk-6.x-1.0-beta5.tar.gz
DL_TRANSLATIONS.zh-cn=	zh-hans-6.x-1.0.tar.gz
DL_TRANSLATIONS.zh-tw=	zh-hant-6.x-1.1.tar.gz

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
